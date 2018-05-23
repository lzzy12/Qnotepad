/*   findreplacebox.h
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
#ifndef FINDREPLACEBOX_H
#define FINDREPLACEBOX_H

#include <QDialog>
#include <QPlainTextEdit>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QString>
#include <QCheckBox>
#include "notepad.h"

namespace Ui {
class FindReplaceBox;
}

class FindReplaceBox : public QDialog
{
    Q_OBJECT

public:
    explicit FindReplaceBox(QWidget *parent = 0);
    ~FindReplaceBox();
    QString getStr();
    bool getBackChecked();

private slots:
    void EnableFind();

private:
    Ui::FindReplaceBox *ui;  
    QLabel *searchLabel = new QLabel("Text to find: ");
    QLineEdit *searchBox = new QLineEdit();
    QPushButton *find = new QPushButton("Find");
    QGridLayout *layout = new QGridLayout();
    QCheckBox *backwardSearch = new QCheckBox();
    QLabel *l_backwardSearch = new QLabel("Search Backwards");

};

#endif // FINDREPLACEBOX_H
