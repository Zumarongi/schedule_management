#include "time_conflict_dialog.h"
#include "ui_time_conflict_dialog.h"

time_conflict_dialog::time_conflict_dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::time_conflict_dialog)
{
    ui->setupUi(this);

}

time_conflict_dialog::~time_conflict_dialog()
{
    delete ui;
}
