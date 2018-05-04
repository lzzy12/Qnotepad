#include "notepad.h"
#include "ui_notepad.h"
#include "about.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QIcon>
#include <QFont>
#include <QFontDialog>
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
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
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
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        ui->textBody->setPlainText(in.readAll());

    }
}

void Notepad::on_actionSave_As_triggered()
{
    saveFile = QFileDialog::getSaveFileName();

    QFile file(saveFile);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << ui->textBody->toPlainText();
    }
}

void Notepad::on_actionFont_triggered()
{   bool ok;
    QFont font = QFontDialog::getFont(&ok);
    if (ok)
        ui->textBody->setFont(font);
}
