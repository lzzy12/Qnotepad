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
