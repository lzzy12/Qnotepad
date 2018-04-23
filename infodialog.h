#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QString data, QWidget *parent = 0);
    ~InfoDialog();
    void setBrowserText(QString data);

private slots:
    void on_pushButton_clicked();

private:
    Ui::InfoDialog *ui;
};

#endif // INFODIALOG_H
