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
    connect(ui->textBody, SIGNAL(undoAvailable(bool)), ui->actionUndo, SLOT(setEnabled(bool)));
    connect(ui->textBody, SIGNAL(redoAvailable(bool)), ui->actionRedo, SLOT(setEnabled(bool)));

}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::SaveFile(QString *file)
{
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
    saveFile = "";      //So that it won't save the new file to the previous opened file.

}

void Notepad::on_actionAbout_triggered()
{
   About about;
   about.setModal(true);
   about.exec();
}




void Notepad::on_actionOpen_triggered()
{
    openFile = QFileDialog::getOpenFileName();
    saveFile = openFile;
    QFile *file = new QFile(openFile);
    if (file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(file);
        ui->textBody->setPlainText(in.readAll());

    }
}

void Notepad::on_actionSave_triggered()
{
    if (saveFile.isEmpty())
        on_actionSave_As_triggered();
    else
        SaveFile(&saveFile);

}

void Notepad::on_actionSave_As_triggered()
{
    saveFile = QFileDialog::getSaveFileName();

    SaveFile(&saveFile);
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
