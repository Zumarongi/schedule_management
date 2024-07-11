#ifndef SIGN_IN_WINDOW_H
#define SIGN_IN_WINDOW_H

#include <QMainWindow>

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
