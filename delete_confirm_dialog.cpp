#include "delete_confirm_dialog.h"
#include "ui_delete_confirm_dialog.h"
#include "account.h"

extern Account *currentAccount;

delete_confirm_dialog::delete_confirm_dialog(task_info_window *parent)
    : QDialog(parent)
    , ui(new Ui::delete_confirm_dialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, [=](){
        currentAccount->delTask(parent->get_currentTask());
        this->close();
    });

    connect(ui->buttonBox, &QDialogButtonBox::rejected, [=](){
        this->close();
    });
}

delete_confirm_dialog::~delete_confirm_dialog()
{
    delete ui;
}
