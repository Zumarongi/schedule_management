#ifndef TASK_INFO_WINDOW_H
#define TASK_INFO_WINDOW_H

#include <QWidget>

namespace Ui {
class task_info_window;
}

class task_info_window : public QWidget
{
    Q_OBJECT

public:
    explicit task_info_window(QWidget *parent = nullptr);
    ~task_info_window();

private:
    Ui::task_info_window *ui;
};

#endif // TASK_INFO_WINDOW_H