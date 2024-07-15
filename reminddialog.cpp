#include "reminddialog.h"
#include "ui_reminddialog.h"

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
    std::string convertTime=std::to_string(min.count()+'.'+sec.count());
    ui->TaskTime->setText(QString::fromStdString(convertTime));
    ui->comboBox->addItem("不提醒");
    if(sec>std::chrono::seconds(60)){
        ui->comboBox->addItem("1分钟");
    }
    if(sec>std::chrono::seconds(300)){
        ui->comboBox->addItem("5分钟");
    }
    if(sec>std::chrono::seconds(600)){
        ui->comboBox->addItem("10分钟");
    }
    if(sec>std::chrono::seconds(1800)){
        ui->comboBox->addItem("30分钟");
    }
    ui->comboBox->setCurrentIndex(0);
    connect(ui->comboBox,&QComboBox::currentIndexChanged,[=](){
        if(ui->comboBox->currentIndex()==1){
            getTask->set_rmTime(getTask->get_rmTime().addSecs(-60));
        }
        if(ui->comboBox->currentIndex()==2){
            getTask->set_rmTime(getTask->get_rmTime().addSecs(-300));
        }
        if(ui->comboBox->currentIndex()==3){
            getTask->set_rmTime(getTask->get_rmTime().addSecs(-600));
        }
        if(ui->comboBox->currentIndex()==4){
            getTask->set_rmTime(getTask->get_rmTime().addSecs(-1800));
        }
    });
    connect(ui->OK_button,&QPushButton::clicked,this,&QDialog::close);
}

remindDialog::~remindDialog()
{
    delete ui;
}

void remindDialog::on_task_info_button_clicked(){
    task_info_window *infoPage=new task_info_window(currenTask);
}
