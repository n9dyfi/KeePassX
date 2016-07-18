/*
 * menumodel.h - <application name>
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


#ifndef MENUMODEL_H
#define MENUMODEL_H

#include <QAbstractListModel>
#include <QStringList>
#include <QVector>

class MenuModel : public QAbstractListModel
{
    Q_OBJECT

public:
    MenuModel(QObject *parent = 0);

    enum RecentRoles {
        TitleRole = Qt::UserRole + 1,
        SubtitleRole,
        PageRole,
        EnableRole
    };

    // When subclassing QAbstractListModel, we must provide implementations of the
    // rowCount() and data() functions.
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;

protected:

    QStringList menuEntries;
    QList<bool> entryEnabled;

signals:

public slots:

};

#endif // MENUMODEL_H
