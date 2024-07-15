#include "get_time_range.h"
#include "mainwindow.h"
#include "ui_get_time_range.h"

extern MainWindow *mainPage;

get_time_range::get_time_range(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::get_time_range)
{
    ui->setupUi(this);
    ui->error_range_warning->hide();
    connect(ui->OK_button,&QPushButton::clicked,[=](){
        mainPage->minTime=ui->min_timeEdit->dateTime();
        mainPage->maxTime=ui->max_timeEdit->dateTime();
        if(mainPage->maxTime<=mainPage->minTime) ui->error_range_warning->show();//总是false
        else{
            emit done_change();
            this->close();
        }
    });
}

get_time_range::~get_time_range()
{
    delete ui;
}
