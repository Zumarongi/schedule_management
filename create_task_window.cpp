#include "create_task_window.h"
#include "ui_create_task_window.h"

create_task_window::create_task_window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::create_task_window)
{
    ui->setupUi(this);
}

create_task_window::~create_task_window()
{
    delete ui;
}
