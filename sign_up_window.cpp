#include "sign_up_window.h"
#include "ui_sign_up_window.h"

sign_up_window::sign_up_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sign_up_window)
{
    ui->setupUi(this);
}

sign_up_window::~sign_up_window()
{
    delete ui;
}
