#include "delete_confirm_dialog.h"
#include "ui_delete_confirm_dialog.h"

delete_confirm_dialog::delete_confirm_dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::delete_confirm_dialog)
{
    ui->setupUi(this);
}

delete_confirm_dialog::~delete_confirm_dialog()
{
    delete ui;
}
