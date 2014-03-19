/******************************************************************************
 * Icinga 2                                                                   *
 * Copyright (C) 2012-2014 Icinga Development Team (http://www.icinga.org)    *
 *                                                                            *
 * This program is free software; you can redistribute it and/or              *
 * modify it under the terms of the GNU General Public License                *
 * as published by the Free Software Foundation; either version 2             *
 * of the License, or (at your option) any later version.                     *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with this program; if not, write to the Free Software Foundation     *
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.             *
 ******************************************************************************/

#ifndef LOGUTILITY_H
#define LOGUTILITY_H

#include "livestatus/historytable.h"

using namespace icinga;

namespace icinga
{

enum LogEntryType {
    LogEntryTypeHostAlert,
    LogEntryTypeHostDowntimeAlert,
    LogEntryTypeHostFlapping,
    LogEntryTypeHostNotification,
    LogEntryTypeHostInitialState,
    LogEntryTypeHostCurrentState,
    LogEntryTypeServiceAlert,
    LogEntryTypeServiceDowntimeAlert,
    LogEntryTypeServiceFlapping,
    LogEntryTypeServiceNotification,
    LogEntryTypeServiceInitialState,
    LogEntryTypeServiceCurrentState,
    LogEntryTypeTimeperiodTransition,
    LogEntryTypeVersion,
    LogEntryTypeInitialStates,
    LogEntryTypeProgramStarting
};

enum LogEntryClass {
    LogEntryClassInfo = 0,
    LogEntryClassAlert = 1,
    LogEntryClassProgram = 2,
    LogEntryClassNotification = 3,
    LogEntryClassPassive = 4,
    LogEntryClassCommand = 5,
    LogEntryClassState = 6,
    LogEntryClassText = 7
};

/**
 * @ingroup livestatus
 */
class LogUtility
{

public:
	static void CreateLogIndex(const String& path, std::map<time_t, String>& index);
	static void CreateLogIndexFileHandler(const String& path, std::map<time_t, String>& index);
	static void CreateLogCache(std::map<time_t, String> index, HistoryTable *table, time_t from, time_t until, const AddRowFunction& addRowFn);
	static Dictionary::Ptr GetAttributes(const String& text);

private:
	LogUtility(void);
};

}

#endif /* LOGUTILITY_H */
