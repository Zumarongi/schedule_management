#include "arrive_remind_time.h"
#include "ui_arrive_remind_time.h"

arrive_remind_time::arrive_remind_time(Task *task,QWidget *parent)
    : currentTask(task)
    , QMainWindow(parent)
    , ui(new Ui::arrive_remind_time)
{
    ui->setupUi(this);
}

arrive_remind_time::~arrive_remind_time()
{
    delete ui;
}
