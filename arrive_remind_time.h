#ifndef ARRIVE_REMIND_TIME_H
#define ARRIVE_REMIND_TIME_H

#include <QMainWindow>
#include "task.h"

namespace Ui {
class arrive_remind_time;
}

class arrive_remind_time : public QMainWindow
{
    Q_OBJECT
    Task *currentTask;

public:
    explicit arrive_remind_time(Task *task,QWidget *parent = nullptr);
    ~arrive_remind_time();

private:
    Ui::arrive_remind_time *ui;
};

#endif // ARRIVE_REMIND_TIME_H
