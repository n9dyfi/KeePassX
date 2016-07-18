/*
 * mainwindow.h - <application name>
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


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>

class MainWindow : public QObject
{
    Q_OBJECT
public:
    explicit MainWindow(QObject *qml, QObject *parent = 0);
    
signals:
    void openPasswordDialog(QString);

public slots:
    void onFileMenu(QString action);

private slots:
    void OnFileNewKdb();

private:
    inline void setupConnections(QObject *qml);
    
};

#endif // MAINWINDOW_H
