#ifndef SIGN_IN_WINDOW_H
#define SIGN_IN_WINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "mainwindow.h"
#include "sign_up_window.h"

namespace Ui {
class sign_in_window;
}

class sign_in_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit sign_in_window(QWidget *parent = nullptr);
    ~sign_in_window();

private:
    Ui::sign_in_window *ui;
};

#endif // SIGN_IN_WINDOW_H
