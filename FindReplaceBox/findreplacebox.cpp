/*   findreplacebox.cpp
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

#include "findreplacebox.h"
#include "ui_findreplacebox.h"

FindReplaceBox::FindReplaceBox(QWidget *parent):
    QDialog(parent),
    ui(new Ui::FindReplaceBox)
{
    ui->setupUi(this);
    setWindowTitle("Find");
    layout->addWidget(searchLabel, 0, 0, 1, 1);
    layout->addWidget(searchBox, 0, 1, 1, 1);
    layout->addWidget(find, 2, 1, 1, 2);
    layout->addWidget(backwardSearch, 3, 0, 1, 2);
    layout->addWidget(l_backwardSearch, 3, 1, 1, 1);
    setLayout(layout);
    setGeometry(geometry().x() + geometry().width()/2, geometry().y() + geometry().height()/2, 250, 100);
    find->setEnabled(false);
    connect(searchBox, SIGNAL(textEdited(QString)), this, SLOT(EnableFind()));
    connect(find, &QPushButton::clicked, this, &FindReplaceBox::accept);
    this->exec();
}

FindReplaceBox::~FindReplaceBox()
{
    delete ui;
}

void FindReplaceBox::EnableFind()
{
    if (!(searchBox->text() == QString()))
        find->setEnabled(true);

    else find->setEnabled(false);
}

QString FindReplaceBox::getStr()
{
    return searchBox->text();
}

bool FindReplaceBox::getBackChecked()
{

        return backwardSearch->isChecked();

}
