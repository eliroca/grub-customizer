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

#ifndef MAINCONTROLLER_H_
#define MAINCONTROLLER_H_

#include <list>
#include "../lib/Type.hpp"

class MainController {
public:
	virtual inline ~MainController(){};

	virtual void syncLoadStateAction() = 0;
	virtual void syncSaveStateAction() = 0;

	virtual void reInitAction(bool burgMode) = 0;
	virtual void dieAction() = 0;
	virtual void loadThreadedAction(bool preserveConfig) = 0;
	virtual void saveThreadedAction() = 0;
	virtual void showConfigSavingErrorAction(std::string errorMessage) = 0;
	virtual void addEntriesAction(std::list<Rule*> entries) = 0;
	virtual void activateSettingsAction() = 0;
	virtual void showReloadRecommendationAction() = 0;
	virtual void selectRulesAction(std::list<Rule*> rules) = 0;
	virtual void selectRuleAction(Rule* rule, bool startEdit) = 0;
};


#endif /* MAINCONTROLLER_H_ */
