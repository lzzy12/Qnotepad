#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

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

private:
    Ui::Notepad *ui;
};

#endif // NOTEPAD_H
