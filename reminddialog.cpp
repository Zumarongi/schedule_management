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
