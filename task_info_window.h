#ifndef TASK_INFO_WINDOW_H
#define TASK_INFO_WINDOW_H

#include "task.h"
#include <QVBoxLayout>
#include <QWidget>

namespace Ui {
class task_info_window;
}

class task_info_window : public QWidget
{
    Q_OBJECT
    Task *currentTask;

    void setupInitValues();
    void setupPageLayout();

public:
    explicit task_info_window(Task *task, QWidget *parent = nullptr);
    ~task_info_window();

    Task *get_currentTask() const;

signals:
    void done_modification();

private:
    Ui::task_info_window *ui;
};

#endif // TASK_INFO_WINDOW_H
