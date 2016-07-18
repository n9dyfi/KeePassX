/*
 * menumodel.cpp - <application name>
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

#include "menumodel.h"

MenuModel::MenuModel(QObject *parent) :
    QAbstractListModel(parent)
{
    QHash<int, QByteArray> roles;
    roles[TitleRole] = "title";
    roles[SubtitleRole] = "subtitle";
    roles[PageRole] = "page";
    roles[EnableRole] = "enable";

    // expose the roles to the QML side so that the ListDelegate can refer
    // to role names "subtitle" and "title".
    setRoleNames(roles);
}

int MenuModel::rowCount(const QModelIndex &parent) const
{
    return menuEntries.count();
}

QVariant MenuModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= menuEntries.size())
        return QVariant();

    if (role == TitleRole)
        return menuEntries.at(index.row()).split("|")[0];
    else if (role == SubtitleRole)
        return QVariant();
    else if (role == EnableRole)
        return entryEnabled.at(index.row());
    else if (role == PageRole)
        return menuEntries.at(index.row()).split("|")[1];
    else
        return QVariant();
}
