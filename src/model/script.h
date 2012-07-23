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
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef GRUB_CUSTOMIZER_SCRIPT_INCLUDED
#define GRUB_CUSTOMIZER_SCRIPT_INCLUDED
#include <string>
#include <list>
#include <cstdlib>
#include <sys/stat.h>
#include "entry.h"
#include "../interface/entryPathFollower.h"
#include "../presenter/commonClass.h"
#include "../lib/md5.h"
#include "../config.h"

struct Script : public EntryPathFollower, public CommonClass {
	enum Exception {
		ELEMENT_NOT_FOUND
	};
	std::string name, fileName;
	bool isCustomScript;
	bool isModified;
	Entry root;
	Script(std::string const& name, std::string const& fileName);
	std::list<Entry>& entries();
	std::list<Entry> const& entries() const;
	bool isInScriptDir(std::string const& cfg_dir) const;
	Entry* getEntryByPath(std::list<std::string> const& path);
	Entry* getEntryByName(std::string const& name, std::list<Entry>& parentList);
	Entry* getEntryByHash(std::string const& hash, std::list<Entry>& parentList);
	void moveToBasedir(std::string const& cfg_dir); //moves the file from any location to grub.d and adds the prefix PS_ (proxified Script) or DS_ (default script)
	bool moveFile(std::string const& newPath, short int permissions = -1);
	std::list<std::string> buildPath(Entry const& entry, Entry const* parent) const;
	std::list<std::string> buildPath(Entry const& entry) const;
	std::string buildPathString(Entry const& entry, bool withOtherEntriesPlaceholder = false) const;
	bool hasEntry(Entry const& entry, Entry const * parent = NULL) const;
};

#endif
