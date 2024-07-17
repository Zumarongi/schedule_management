#include "inprogress_rmdialog.h"
#include "ui_inprogress_rmdialog.h"

inProgress_rmDialog::inProgress_rmDialog(Task *task,QWidget *parent)
    : currenTask(task)
    , QDialog(parent)
    , ui(new Ui::inProgress_rmDialog)
{
    ui->setupUi(this);
    task->set_isReminded(true);
    std::filesystem::path task_path = ROOTDIR + "/data/" + currenTask->get_owner().toStdString() + "/" + std::to_string(currenTask->get_taskId()) + ".task";
    currenTask->saveToFile(task_path);
    ui->taskName_label->setText(task->get_taskName());
}

inProgress_rmDialog::~inProgress_rmDialog()
{
    delete ui;
}

void inProgress_rmDialog::on_OK_pushButton_clicked()
{
    this->close();
}

