#ifndef TASK_INFO_WINDOW_H
#define TASK_INFO_WINDOW_H

#include <QWidget>
#include "task.h"

namespace Ui {
class task_info_window;
}

class task_info_window : public QWidget
{
    Q_OBJECT
    Task *currentTask;

public:
    explicit task_info_window(Task *getTask,QWidget *parent = nullptr);
    ~task_info_window();

private:
    Ui::task_info_window *ui;
};

#endif // TASK_INFO_WINDOW_H
