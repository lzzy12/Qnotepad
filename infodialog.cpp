#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QString data, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
    setBrowserText(data);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}
void InfoDialog::setBrowserText(QString data)
{
    ui->textBrowser->setText(data);
}

void InfoDialog::on_pushButton_clicked()
{
    this->close();
}
