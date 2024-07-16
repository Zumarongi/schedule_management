#include "delete_confirm_dialog.h"
#include "ui_delete_confirm_dialog.h"
#include "account.h"

extern Account *currentAccount;

delete_confirm_dialog::delete_confirm_dialog(Task *task,task_info_window *parent)
    : currenTask(task)
    , QDialog(parent)
    , ui(new Ui::delete_confirm_dialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, [=](){
        currentAccount->delTask(task);
        emit doneDel();
        this->close();
    });

    connect(ui->buttonBox, &QDialogButtonBox::rejected, [=](){
        emit doneDel();
        this->close();
    });
}

delete_confirm_dialog::~delete_confirm_dialog()
{
    delete ui;
}
