#include "get_task_range.h"
#include "ui_get_task_range.h"

get_task_range::get_task_range(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::get_task_range)
{
    ui->setupUi(this);
    ui->error_range_warning->hide();
    if(ui->min_timeEdit->isWindowModified())
        currentAccount->minTime=timeformat::toTime_t(ui->min_timeEdit->dateTime());
    if(ui->max_timeEdit->isWindowModified())
        currentAccount->maxTime=timeformat::toTime_t(ui->max_timeEdit->dateTime());
    /*while(currentAccount->maxTime<=currentAccount->minTime){
        ui->error_range_warning->show();
    }
    ui->error_range_warning->hide();*/
    connect(ui->OK_button,&QPushButton::clicked,[=](){
        if(currentAccount->maxTime<=currentAccount->minTime) ui->error_range_warning->show();//总是false
        else this->close();
    });
}

get_task_range::~get_task_range()
{
    delete ui;
}
