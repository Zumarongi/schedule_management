#include "time_conflict_dialog.h"
#include "ui_time_conflict_dialog.h"

time_conflict_dialog::time_conflict_dialog(create_task_window *parent)
    : QDialog(parent)
    , ui(new Ui::time_conflict_dialog)
{
    ui->setupUi(this);

    ui->label->setText("该任务与其他任务时间冲突，\n确认创建？");
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
}

time_conflict_dialog::time_conflict_dialog(task_info_window *parent)
    : QDialog(parent)
    , ui(new Ui::time_conflict_dialog)
{
    ui->setupUi(this);

    ui->label->setText("该任务与其他任务时间冲突，\n是否保存？");
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Save | QDialogButtonBox::Cancel);
}

time_conflict_dialog::~time_conflict_dialog()
{
    delete ui;
}
