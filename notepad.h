/*   notepad.h
*    Copyright 2018, Shivam Jha
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

#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class Notepad;
}

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = 0);
    ~Notepad();

private slots:

    void on_actionNew_triggered();

    void on_actionAbout_triggered();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();


    void on_actionFont_triggered();

    void on_actionUndo_triggered();


    void on_actionRedo_triggered();

private:
    Ui::Notepad *ui;
    QString openFile;
    QString saveFile;
    void SaveFile(QString *file);
};

#endif // NOTEPAD_H
