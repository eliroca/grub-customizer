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

#ifndef TRAIT_LOGGERAWARE_INCLUDED
#define TRAIT_LOGGERAWARE_INCLUDED

#include "../Logger.h"
#include "../Exception.h"
#include "../AutoPtr.h"

class Trait_LoggerAware {
protected:
	mutable AutoPtr<Logger> logger;
public:
	Trait_LoggerAware() {}

	void setLogger(AutoPtr<Logger> logger) {
		this->logger = logger;
	}

	AutoPtr<Logger> getLogger() {
		return this->logger;
	}

	const AutoPtr<Logger> getLogger() const {
		return this->logger;
	}

	AutoPtr<Logger> getLoggerPtr() {
		return this->logger;
	}

	bool hasLogger() const {
		return this->logger;
	}
protected:
	void log(std::string const& message, Logger::Priority prio) const {
		if (this->logger) {
			this->logger->log(message, prio);
		}
	}
};


#endif /* TRAIT_LOGGERAWARE_INCLUDED */
