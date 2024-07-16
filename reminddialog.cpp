#include "reminddialog.h"
#include "ui_reminddialog.h"
#include "mainwindow.h"

extern MainWindow *mainPage;

remindDialog::remindDialog(Task *getTask,QWidget *parent)
    : currenTask(getTask)
    , QDialog(parent)
    , ui(new Ui::remindDialog)
{
    ui->setupUi(this);
    ui->TaskName->setText(currenTask->get_taskName());
    std::chrono::milliseconds lastTime=currenTask->get_stTime()-QDateTime::currentDateTime();
    std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>(lastTime);
    std::chrono::minutes min = std::chrono::duration_cast<std::chrono::minutes>(sec);
    sec-=min;
    std::string convertTime=std::to_string(min.count())+"分"+std::to_string(sec.count())+"秒";
    ui->TaskTime->setText(QString::fromStdString(convertTime));
    ui->comboBox->addItem("不提醒");
    if(min>std::chrono::minutes(1)){
        ui->comboBox->addItem("1分钟");
    }
    if(min>std::chrono::minutes(5)){
        ui->comboBox->addItem("5分钟");
    }
    if(min>std::chrono::minutes(10)){
        ui->comboBox->addItem("10分钟");
    }
    if(min>std::chrono::minutes(30)){
        ui->comboBox->addItem("30分钟");
    }
    ui->comboBox->setCurrentIndex(0);

    connect(ui->OK_button,&QPushButton::clicked,[=](){
        if(ui->comboBox->currentIndex()==1){
            getTask->set_isReminded(false);
            new_rmTime=QTime::fromMSecsSinceStartOfDay((getTask->get_stTime()-QDateTime::currentDateTime()).count()-60000);
            getTask->set_rmTime(new_rmTime);
        }
        if(ui->comboBox->currentIndex()==2){
            getTask->set_isReminded(false);
            new_rmTime=QTime::fromMSecsSinceStartOfDay((getTask->get_stTime()-QDateTime::currentDateTime()).count()-300000);
            getTask->set_rmTime(new_rmTime);
        }
        if(ui->comboBox->currentIndex()==3){
            getTask->set_isReminded(false);
            new_rmTime=QTime::fromMSecsSinceStartOfDay((getTask->get_stTime()-QDateTime::currentDateTime()).count()-600000);
            getTask->set_rmTime(new_rmTime);
        }
        if(ui->comboBox->currentIndex()==4){
            getTask->set_isReminded(false);
            new_rmTime=QTime::fromMSecsSinceStartOfDay((getTask->get_stTime()-QDateTime::currentDateTime()).count()-1800000);
            getTask->set_rmTime(new_rmTime);
        }
        this->close();
    });
}

remindDialog::~remindDialog()
{
    delete ui;
}

void remindDialog::on_task_info_button_clicked(){
    task_info_window *infoPage=new task_info_window(currenTask);
    infoPage->show();
    mainPage->close();
}
