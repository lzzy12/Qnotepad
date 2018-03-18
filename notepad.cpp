#include "notepad.h"
#include "ui_notepad.h"
#include "about.h"
Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
    setCentralWidget(ui->textBody);
}

Notepad::~Notepad()
{
    delete ui;
}



void Notepad::on_actionNew_triggered()
{
    ui->textBody->document()->setPlainText(QString());

}

void Notepad::on_actionAbout_triggered()
{
   About about;
   about.setModal(true);
   about.exec();
}
