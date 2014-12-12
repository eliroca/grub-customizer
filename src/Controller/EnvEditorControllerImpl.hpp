/*
 * Copyright (C) 2010-2011 Daniel Richter <danielrichter2007@web.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef ENVEDITORCONTROLLERIMPL_H_
#define ENVEDITORCONTROLLERIMPL_H_

#include <libintl.h>
#include <locale.h>
#include <sstream>
#include "../config.hpp"
#include "../Model/DeviceMap.hpp"

#include "../Model/Env.hpp"

#include "../Model/MountTable.hpp"

#include "../View/EnvEditor.hpp"
#include "../View/Trait/ViewAware.hpp"

#include "ControllerAbstract.hpp"
#include "EnvEditorController.hpp"


class EnvEditorControllerImpl :
	public ControllerAbstract,
	public EnvEditorController,
	public View_Trait_ViewAware<View_EnvEditor>,
	public Model_Env_Connection,
	public Bootstrap_Application_Object_Connection
{
	Model_MountTable* mountTable;
	Model_DeviceMap* deviceMap;

public:
	void setMountTable(Model_MountTable& mountTable) {
		this->mountTable = &mountTable;
	}

	void setDeviceMap(Model_DeviceMap& deviceMap) {
		this->deviceMap = &deviceMap;
	}


	void showAction(bool resetPartitionChooser = false) {
		this->logActionBegin("show");
		try {
			this->view->setEnvSettings(this->env->getProperties(), this->env->getRequiredProperties(), this->env->getValidProperties());
			this->view->setRootDeviceName(this->env->rootDeviceName);
			this->view->show(false);
		} catch (Exception const& e) {
			this->applicationObject->onError.exec(e);
		}
		this->logActionEnd();
	}


	EnvEditorControllerImpl() : ControllerAbstract("env-editor"),
		 mountTable(NULL),
		 deviceMap(NULL)
	{
	}

	void initViewEvents() override
	{
		using namespace std::placeholders;

		this->view->onMountSubmountpointClick = std::bind(std::mem_fn(&EnvEditorControllerImpl::mountSubmountpointAction), this, _1);
		this->view->onUmountSubmountpointClick = std::bind(std::mem_fn(&EnvEditorControllerImpl::umountSubmountpointAction), this, _1);
		this->view->onSwitchPartition = std::bind(std::mem_fn(&EnvEditorControllerImpl::switchPartitionAction), this, _1);
		this->view->onSwitchBootloaderType = std::bind(std::mem_fn(&EnvEditorControllerImpl::switchBootloaderTypeAction), this, _1);
		this->view->onOptionChange = std::bind(std::mem_fn(&EnvEditorControllerImpl::updateGrubEnvOptionsAction), this);
		this->view->onApplyClick = std::bind(std::mem_fn(&EnvEditorControllerImpl::applyAction), this, _1);
		this->view->onExitClick = std::bind(std::mem_fn(&EnvEditorControllerImpl::exitAction), this);
	}

	void initApplicationEvents() override
	{
		using namespace std::placeholders;

		this->applicationObject->onEnvEditorShowRequest.addHandler(std::bind(std::mem_fn(&EnvEditorControllerImpl::showAction), this, false));
	}

	
	//partition chooser
	void mountSubmountpointAction(std::string const& submountpoint) {
		this->logActionBegin("mount-submountpoint");
		try {
			try {
				this->mountTable->getEntryRefByMountpoint(PARTCHOOSER_MOUNTPOINT + submountpoint).mount();
			} catch (MountException const& e){
				this->view->showErrorMessage(View_EnvEditor::SUB_MOUNT_FAILED);
				this->view->setSubmountpointSelectionState(submountpoint, false);
				this->view->show();
			} catch (SystemException const& e){
				this->view->setSubmountpointSelectionState(submountpoint, false);
				this->view->show();
			}
		} catch (Exception const& e) {
			this->applicationObject->onError.exec(e);
		}
		this->logActionEnd();
	}

	void umountSubmountpointAction(std::string const& submountpoint) {
		this->logActionBegin("umount-submountpoint");
		try {
			try {
				this->mountTable->getEntryRefByMountpoint(PARTCHOOSER_MOUNTPOINT + submountpoint).umount();
			} catch (UMountException const& e){
				this->view->showErrorMessage(View_EnvEditor::SUB_UMOUNT_FAILED);
				this->view->setSubmountpointSelectionState(submountpoint, true);
				this->view->show();
			} catch (SystemException const& e){
				this->view->setSubmountpointSelectionState(submountpoint, true);
				this->view->show();
			}
		} catch (Exception const& e) {
			this->applicationObject->onError.exec(e);
		}
		this->logActionEnd();
	}

	void generateSubmountpointSelection(std::string const& prefix) {
		this->view->removeAllSubmountpoints();
	
		//create new submountpoint checkbuttons
		for (Model_MountTable::const_iterator iter = mountTable->begin(); iter != mountTable->end(); iter++){
			if (iter->mountpoint.length() > prefix.length() && iter->mountpoint.substr(0, prefix.length()) == prefix
			 && iter->mountpoint != prefix + "/dev"
			 && iter->mountpoint != prefix + "/proc"
			 && iter->mountpoint != prefix + "/sys"
			) {
				this->view->addSubmountpoint(iter->mountpoint.substr(prefix.length()), iter->isMounted);
			}
		}
	}


	// env editor
	void switchPartitionAction(std::string const& newPartition) {
		this->logActionBegin("switch-partition");
		try {
			if (this->mountTable->getEntryByMountpoint(PARTCHOOSER_MOUNTPOINT).isMounted) {
				this->mountTable->umountAll(PARTCHOOSER_MOUNTPOINT);
				this->mountTable->clear(PARTCHOOSER_MOUNTPOINT);
			}
			this->view->removeAllSubmountpoints();
			std::string selectedDevice = newPartition;
			if (newPartition != "") {
				mkdir(PARTCHOOSER_MOUNTPOINT, 0755);
				try {
					mountTable->clear(PARTCHOOSER_MOUNTPOINT);
					mountTable->mountRootFs(selectedDevice, PARTCHOOSER_MOUNTPOINT);
					this->env->init(env->burgMode ? Model_Env::BURG_MODE : Model_Env::GRUB_MODE, PARTCHOOSER_MOUNTPOINT);
					this->generateSubmountpointSelection(PARTCHOOSER_MOUNTPOINT);
					this->showAction();
				}
				catch (MountException const& e) {
					this->view->showErrorMessage(View_EnvEditor::MOUNT_FAILED);
					this->switchPartitionAction("");
				}
				catch (MissingFstabException const& e) {
					this->view->showErrorMessage(View_EnvEditor::MOUNT_ERR_NO_FSTAB);
					mountTable->getEntryRefByMountpoint(PARTCHOOSER_MOUNTPOINT).umount();
					this->switchPartitionAction("");
				}
			} else {
				this->env->init(env->burgMode ? Model_Env::BURG_MODE : Model_Env::GRUB_MODE, selectedDevice);
				this->showAction(true);
			}
		} catch (Exception const& e) {
			this->applicationObject->onError.exec(e);
		}
		this->logActionEnd();
	}

	void switchBootloaderTypeAction(int newTypeIndex) {
		this->logActionBegin("switch-bootloader-type");
		try {
			this->env->init(newTypeIndex == 0 ? Model_Env::GRUB_MODE : Model_Env::BURG_MODE, this->env->cfg_dir_prefix);
			this->showAction();
		} catch (Exception const& e) {
			this->applicationObject->onError.exec(e);
		}
		this->logActionEnd();
	}

	void updateGrubEnvOptionsAction() {
		this->logActionBegin("update-grub-env-options");
		try {
			this->env->setProperties(this->view->getEnvSettings());
			this->showAction();
		} catch (Exception const& e) {
			this->applicationObject->onError.exec(e);
		}
		this->logActionEnd();
	}

	void applyAction(bool saveConfig) {
		this->logActionBegin("apply");
		try {
			this->getAllControllers().settingsController->hideAction();
			this->getAllControllers().trashController->hideAction();
			bool isBurgMode = this->view->getBootloaderType() == 1;
			view->hide();
	
			if (saveConfig) {
				this->env->save();
			}
			this->deviceMap->clearCache();
			this->getAllControllers().mainController->reInitAction(isBurgMode);
		} catch (Exception const& e) {
			this->applicationObject->onError.exec(e);
		}
		this->logActionEnd();
	}


	void exitAction() {
		this->logActionBegin("exit");
		try {
			this->applicationObject->shutdown();
		} catch (Exception const& e) {
			this->applicationObject->onError.exec(e);
		}
		this->logActionEnd();
	}

};

#endif
