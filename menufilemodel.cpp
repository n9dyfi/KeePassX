/*
 * menufilemodel.cpp - <application name>
 * Copyright (C) 2016 n9dyfi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "menufilemodel.h"

MenuFileModel::MenuFileModel(QObject *parent) :
    MenuModel(parent)
{

    menuEntries << "New Database...|FileNewAction"
                << "Open Database...|OpenDatabase.qml"
                << "Bookmarks|Bookmarks.qml"
                << "Close Database|CloseDatabase.qml"
                << "Save Database|SaveDatabase.qml"
                << "Save Database As...|SaveDatabaseAs.qml"
                << "Database Settings...|DatabaseSettings.qml"
                << "Change Master Key...|ChangeMasterKey.qml"
                << "Import from...|ImportFrom.qml"
                << "Export to...|ExportTo.qml"
                << "Lock Workspace|LockWorkspace.qml"
                << "Quit|Quit.qml";

    entryEnabled << true
                 << true
                 << true
                 << false
                 << false
                 << false
                 << false
                 << false
                 << true
                 << false
                 << false
                 << true;

}
