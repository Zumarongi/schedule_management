#include "get_time_range.h"
#include "ui_get_time_range.h"

get_time_range::get_time_range(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::get_time_range)
{
    ui->setupUi(this);
    ui->error_range_warning->hide();
    currentAccount->minTime=timeformat::toTime_t(ui->min_timeEdit->dateTime());
    currentAccount->maxTime=timeformat::toTime_t(ui->max_timeEdit->dateTime());
    while(currentAccount->maxTime<=currentAccount->minTime){
        ui->error_range_warning->show();
    }
    ui->error_range_warning->hide();
    connect(ui->OK_button,&QPushButton::clicked,[=](){
            this->close();
    });
}

get_time_range::~get_time_range()
{
    delete ui;
}
