#include "task_info_window.h"
#include "ui_task_info_window.h"
#include "mainwindow.h"

extern MainWindow *mainPage;

task_info_window::task_info_window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::task_info_window)
{
    ui->setupUi(this);

    connect(ui->pushButton_saveChanges,&QPushButton::clicked,[=](){\

        mainPage->show();
        this->close();
    });
}

task_info_window::~task_info_window()
{
    delete ui;
}
