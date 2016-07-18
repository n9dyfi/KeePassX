/*
 * keepassx.h - <application name>
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


#ifndef KEEPASSX_H
#define KEEPASSX_H

#include <QPixmap>

// global defines

#define APP_DISPLAY_NAME    "KeePassX"
#define APP_CODE_NAME       "keepassx"
#define APP_SHORT_FUNC      "Password Manager"
#define APP_LONG_FUNC       "Cross Platform Password Manager"
#define APP_VERSION         "0.4.4"

#define BUILTIN_ICONS 69

#define KEEPASS_LITTLE_ENDIAN
//#define KEEPASS_BIG_ENDIAN

#include "KpxConfig.h"

#include "plugins/interfaces/IIconTheme.h"

extern QString PluginLoadError;
extern IIconTheme* IconLoader;
extern KpxConfig *config;
extern QString AppDir;
extern QString HomeDir;
extern QString DataDir;
extern bool TrActive;
extern QString DetailViewTemplate;
extern QPixmap *EntryIcons;
extern bool EventOccurred;
extern bool EventOccurredBlock;

#endif // KEEPASSX_H
