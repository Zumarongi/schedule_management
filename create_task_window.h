#ifndef CREATE_TASK_WINDOW_H
#define CREATE_TASK_WINDOW_H

#include <QDateTime>
#include <QWidget>

namespace Ui {
class create_task_window;
}

class create_task_window : public QWidget
{
    Q_OBJECT

    QDateTime init_stTime, init_edTime;

    void getInitTime();

    void setupInitValues();
    void setupPageLayout();

public:
    explicit create_task_window(QWidget *parent = nullptr);
    ~create_task_window();

signals:
    void done_creation();

private:
    Ui::create_task_window *ui;
};

#endif // CREATE_TASK_WINDOW_H
