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
    std::string convertTime=std::to_string(sec.count());
    ui->TaskTime->setText(QString::fromStdString(convertTime));
    ui->comboBox->addItem("不提醒");
    ui->comboBox->addItem("1分钟");
    ui->comboBox->addItem("5分钟");
    ui->comboBox->addItem("10分钟");
    ui->comboBox->addItem("30分钟");
    ui->comboBox->setCurrentIndex(0);
    //计算是否超时
    connect(ui->OK_button,&QPushButton::clicked,this,&QDialog::close);
}

remindDialog::~remindDialog()
{
    delete ui;
}

void remindDialog::on_task_info_button_clicked(){
    task_info_window *infoPage=new task_info_window(currenTask);
}
