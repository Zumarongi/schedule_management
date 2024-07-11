#include "sign_in_window.h"
#include "ui_sign_in_window.h"

sign_in_window::sign_in_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sign_in_window)
{
    ui->setupUi(this);
}

sign_in_window::~sign_in_window()
{
    delete ui;
}
