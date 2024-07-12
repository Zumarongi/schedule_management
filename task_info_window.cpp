#include "task_info_window.h"
#include "ui_task_info_window.h"

task_info_window::task_info_window(Task *getTask,QWidget *parent)
    : currentTask(getTask)
    ,QWidget(parent)
    , ui(new Ui::task_info_window)
{
    ui->setupUi(this);
}

task_info_window::~task_info_window()
{
    delete ui;
}
