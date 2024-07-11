#ifndef SIGN_UP_WINDOW_H
#define SIGN_UP_WINDOW_H

#include <QMainWindow>

namespace Ui {
class sign_up_window;
}

class sign_up_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit sign_up_window(QWidget *parent = nullptr);
    ~sign_up_window();

private:
    Ui::sign_up_window *ui;
};

#endif // SIGN_UP_WINDOW_H
