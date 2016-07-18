/*
 * mainwindow.cpp - <application name>
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


#include "mainwindow.h"
#include "database.h"       // IDatabase
#include "kdb3database.h"   // Kdb3Database

MainWindow::MainWindow(QObject *qml, QObject *parent) :
    QObject(parent)
{
    setupConnections(qml);
}

void MainWindow::setupConnections(QObject *qml){
    // Connect QML signals to C++ slots
    connect(qml, SIGNAL(fileMenu(QString)), this, SLOT(onFileMenu(QString)));
    // Connect C++ signals to QML signals
    connect(this, SIGNAL(openPasswordDialog(QString)), qml, SIGNAL(openPasswordDialog(QString)));
}

// Process all File menu actions (QML signal onFileMenu)
void MainWindow::onFileMenu(QString action) {
    if(action==QString("FileNewAction"))
    {
        OnFileNewKdb();
        return;
    }
}

void MainWindow::OnFileNewKdb(){
    IDatabase* db_new=dynamic_cast<IDatabase*>(new Kdb3Database());
    db_new->create();
    emit(openPasswordDialog("New Database"));

#if 0
    PasswordDialog dlg(this,PasswordDialog::Mode_Set,PasswordDialog::Flag_None,"New Database");
    if(dlg.exec()==PasswordDialog::Exit_Ok){
        if(FileOpen)
            if(!closeDatabase())return;
        if (IsLocked)
            resetLock();
        db=db_new;
        db->setKey(dlg.password(),dlg.keyFile());
        db->generateMasterKey();
        updateCurrentFile(QString());
        GroupView->db=db;
        EntryView->db=db;
        GroupView->createItems();
        EntryView->showGroup(NULL);
        setStateFileOpen(true);
        setStateFileModified(true);
        setupDatabaseConnections(db);
        setStateGroupSelected(NONE);
        setStateEntrySelected(NONE);
        GroupView->createGroup("Internet", 1);
        GroupView->createGroup("eMail", 19);
    }
    else{
        delete db_new;
    }
#endif
}


