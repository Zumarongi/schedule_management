#ifndef CREATE_TASK_WINDOW_H
#define CREATE_TASK_WINDOW_H

#include <QMainWindow>

namespace Ui {
class create_task_window;
}

class create_task_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit create_task_window(QWidget *parent = nullptr);
    ~create_task_window();

private:
    Ui::create_task_window *ui;
};

#endif // CREATE_TASK_WINDOW_H
