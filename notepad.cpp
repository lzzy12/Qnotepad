#include "notepad.h"
#include "ui_notepad.h"
#include "about.h"
#include "infodialog.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QIcon>
Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
    setWindowTitle("QNotepad");
    setWindowIcon(QIcon(":/icons/icons/qnotepad.png"));
    setCentralWidget(ui->textBody);
}

Notepad::~Notepad()
{
    delete ui;
}



void Notepad::on_actionNew_triggered()
{
    ui->textBody->document()->setPlainText(QString());
    saveFile = "";

}

void Notepad::on_actionAbout_triggered()
{
   About about;
   about.setModal(true);
   about.exec();
}


void Notepad::on_actionSave_triggered()
{
    if (saveFile == "")
        saveFile = QFileDialog::getSaveFileName();

    QFile file(saveFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        InfoDialog dialog("Cannot open File for writting");
        dialog.exec();
    }
    else
    {
        QTextStream out(&file);
        out << ui->textBody->toPlainText();
    }
}

void Notepad::on_actionOpen_triggered()
{
    openFile = QFileDialog::getOpenFileName();
    saveFile = openFile;
    QFile file(openFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        InfoDialog dialog("<font color=\"red\">I/O ERROR:</font> Cannot open File for reading");
        dialog.exec();
    }
    else
    {
        QTextStream in(&file);
        ui->textBody->setPlainText(in.readAll());

    }
}

void Notepad::on_actionSave_As_triggered()
{
    saveFile = QFileDialog::getSaveFileName();

    QFile file(saveFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        InfoDialog dialog("Cannot open File for writting");
        dialog.exec();
    }
    else
    {
        QTextStream out(&file);
        out << ui->textBody->toPlainText();
    }
}
