#include "reminddialog.h"
#include "ui_reminddialog.h"

remindDialog::remindDialog(Task *getTask,QWidget *parent)
    : currenTask(getTask)
    , QDialog(parent)
    , ui(new Ui::remindDialog)
{
    ui->setupUi(this);
    ui->TaskName->setText(currenTask->get_taskName());

}

remindDialog::~remindDialog()
{
    delete ui;
}

void remindDialog::on_task_info_button_clicked(){
    task_info_window *infoPage=new task_info_window(currenTask);
}
