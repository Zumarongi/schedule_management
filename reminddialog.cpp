#include "reminddialog.h"
#include "ui_reminddialog.h"
#include "mainwindow.h"
#include <QHBoxLayout>

extern MainWindow *mainPage;

void remindDialog::setLayout(){
    this->setFixedSize(450,350);

    QHBoxLayout *firstLayout = new QHBoxLayout;         //第一行
    {
        ui->label_3->setFixedSize(55,30);
        ui->label_3->move(80,50);
        ui->label_3->setAlignment(Qt::AlignCenter);
        firstLayout->addWidget(ui->label_3);
        ui->TaskName->setFixedSize(70,30);
        ui->TaskName->move(140,50);
        ui->TaskName->setAlignment(Qt::AlignCenter);
        firstLayout->addWidget(ui->TaskName);
        ui->label->setFixedSize(30,30);
        ui->label->move(215,50);
        ui->label->setAlignment(Qt::AlignCenter);
        firstLayout->addWidget(ui->label);
        ui->TaskTime->setFixedSize(50,30);
        ui->TaskTime->move(250,50);
        ui->TaskTime->setAlignment(Qt::AlignCenter);
        firstLayout->addWidget(ui->TaskTime);
        ui->label_2->setFixedSize(60,30);
        ui->label_2->move(305,50);
        ui->label_2->setAlignment(Qt::AlignCenter);
        firstLayout->addWidget(ui->label_2);
    }

    ui->task_info_button->setFixedSize(100,30);
    ui->task_info_button->move(175,100);
    ui->task_info_button->setStyleSheet("QPushButton{border-radius:8px;background-color:#148AFF;color:#FFFFFF;}");

    ui->remind_again->setFixedSize(120,30);
    ui->remind_again->move(180,150);

    ui->comboBox->move(130,190);

    ui->OK_button->setFixedSize(60,30);
    ui->OK_button->move(195,260);
    ui->OK_button->setStyleSheet("QPushButton{border-radius:8px;background-color:#148AFF;color:#FFFFFF;}");
}

remindDialog::remindDialog(Task *getTask,QWidget *parent)
    : currenTask(getTask)
    , QDialog(parent)
    , ui(new Ui::remindDialog)
{
    ui->setupUi(this);
    ui->TaskName->setText(currenTask->get_taskName());

    setLayout();


    //内容显示
    std::chrono::milliseconds lastTime=currenTask->get_stTime()-QDateTime::currentDateTime();
    std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>(lastTime);
    std::chrono::minutes min = std::chrono::duration_cast<std::chrono::minutes>(sec);
    sec-=min;
    std::string convertTime=std::to_string(min.count())+"分钟";
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

    //设置再次提醒时间
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

        std::filesystem::path task_path = ROOTDIR + "/data/" + currenTask->get_owner().toStdString() + "/" + std::to_string(currenTask->get_taskId()) + ".task";
        currenTask->saveToFile(task_path);

        this->close();
    });
}

remindDialog::~remindDialog()
{
    delete ui;
}

void remindDialog::on_task_info_button_clicked(){//查看任务
    task_info_window *infoPage=new task_info_window(currenTask);
    infoPage->show();
    mainPage->close();
}
