/*   notepad.cpp
 *
 *    Copyright 2018 Shivam Jha
 *    This file is part of Notepadpp.
 *    Notepadpp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    Notepadpp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "notepad.h"
#include "ui_notepad.h"
#include "about.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QIcon>
#include <QFont>
#include <QFontDialog>
#include <QTextCursor>
#include <QMessageBox>
#include <findreplacebox.h>
#include <QCloseEvent>
#include <QMainWindow>
#if 0
#include <QtDebug>
#endif
Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
    setWindowTitle("QNotepad");
    setWindowIcon(QIcon(":/icons/icons/qnotepad.png"));
    setCentralWidget(ui->textBody);
    //Enabling the options, only when applicable
    connect(ui->textBody, &QPlainTextEdit::undoAvailable, ui->actionUndo, &QAction::setEnabled);
    connect(ui->textBody, &QPlainTextEdit::redoAvailable, ui->actionRedo, &QAction::setEnabled);
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::SaveFile(QString *file)
{
    if (file->isEmpty())
        on_actionSave_triggered();

    QFile *File = new QFile(*file);
    if (File->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(File);
        out << ui->textBody->toPlainText();
    }

}

void Notepad::on_actionNew_triggered()
{
    ui->textBody->document()->setPlainText(QString());
    currFile.clear();      //So that it won't save the new file to the previous opened file.

}

void Notepad::on_actionAbout_triggered()
{
   About about;
   about.setModal(true);
   about.exec();
}




void Notepad::on_actionOpen_triggered()
{
    currFile = QFileDialog::getOpenFileName();
    QFile *file = new QFile(currFile);
    if (file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(file);
        ui->textBody->setPlainText(in.readAll());

    }

}

void Notepad::on_actionSave_triggered()
{
    if (currFile.isEmpty())
        on_actionSave_As_triggered();
    else
        SaveFile(&currFile);

}

void Notepad::on_actionSave_As_triggered()
{
    currFile = QFileDialog::getSaveFileName();

    SaveFile(&currFile);
}

void Notepad::on_actionFont_triggered()
{
    //Takes font details from user with a GUI based dialog
    bool ok;
    QFont font = QFontDialog::getFont(&ok);

    //Set the font as per selection by the user!
    if (ok)
    {
        QTextCursor *cursor = new QTextCursor(ui->textBody->textCursor());

        if (!cursor->hasSelection())
            ui->textBody->setFont(font);
    }

}

void Notepad::on_actionUndo_triggered()
{
    ui->textBody->undo();
}

void Notepad::on_actionRedo_triggered()
{
    ui->textBody->redo();
}

void Notepad::on_actionFind_triggered()
{
    FindReplaceBox *searchWindow = new FindReplaceBox;
    QString searchString = searchWindow->getStr();
    bool searchBack = searchWindow->getBackChecked();
    if  (searchBack)
        ui->textBody->find(searchString, QTextDocument::FindBackward);

    else ui->textBody->find(searchString);

}

void Notepad::closeEvent (QCloseEvent *event)
{

    QFile *file = new QFile(currFile);
    if ((file->open(QIODevice::ReadOnly | QIODevice::Text)) || ((currFile.isEmpty()) && (ui->textBody->toPlainText() != QString())))
    {
       QTextStream *in = new QTextStream(file);
       if (((ui->textBody->toPlainText() != QString()) && (in->readAll() != ui->textBody->toPlainText())) || ((currFile.isEmpty()) && (ui->textBody->toPlainText() != QString())))
       {
            QMessageBox::StandardButton resBtn = QMessageBox::warning(this, tr("File Not Saved!!"),
                                                                        tr("You are trying to close an unsaved file. "
                                                                           "Do you want to save before closing?\n"),
                                                                        QMessageBox::Cancel | QMessageBox::No |
                                                                        QMessageBox::Yes,
                                                                        QMessageBox::Yes);
            if (resBtn == QMessageBox::Yes)
            {
                SaveFile(&currFile);
                event->accept();
            }

            else if (resBtn == QMessageBox::No)
            {
                event->accept();
            }
            else
            {
                event->ignore();
            }
        }
       else event->accept();
    }
    else event->accept();
}
