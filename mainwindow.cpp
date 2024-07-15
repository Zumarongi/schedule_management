#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "qmenu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);

    remindThread * arrving_remind=new remindThread;
    arrving_remind->start();

    ui->auto_delete->setFixedSize(100,20);
    ui->auto_delete->move(30,30);

    ui->lineEdit_search->setFixedSize(500,30);
    ui->lineEdit_search->move(150,25);
    ui->lineEdit_search->setStyleSheet("QLineEdit{border-radius:15px;}");
    ui->search_button->setFixedSize(50,30);
    ui->search_button->move(600,25);
    ui->search_button->setStyleSheet("QPushButton{border-radius:15px;background-color:#148AFF;}");
    ui->add_task_button->setFixedSize(40,40);
    ui->add_task_button->move(700,15);
    ui->add_task_button->setStyleSheet("QPushButton{border-radius:20px;background-color:#148AFF;}");
    ui->not_find_warning->hide();
    ui->not_find_warning->setFixedSize(450,20);
    ui->not_find_warning->move(165,55);
    ui->not_find_warning->setStyleSheet("QLabel{background-color:#FFFFFF;}");
    //ui->scrollArea->setFixedSize(790,520);
    //ui->scrollArea->move(10,80);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setWidgetResizable(true);
    contentWidget = new QWidget;
    layout = new QVBoxLayout(contentWidget);                //记得调整间距
    ui->scrollArea->setWidget(contentWidget);
    layout->setContentsMargins(35,5,35,5);
    /*QPushButton *button=new QPushButton;
    button->setFixedSize(700,40);
    layout->addWidget(button);
    QPushButton *button1=new QPushButton;
    button1->setFixedSize(700,40);
    layout->addWidget(button1);
    */
    if(currentAccount->get_doneAndDel()) del_done_task();

    choosePrio=6;
    chooseCtg=3;
    maxTime=QDateTime::currentDateTime();
    minTime=QDateTime();
    showButton();

    ui->min_dateTimeEdit->setMinimumDateTime(QDateTime::currentDateTime());
    ui->min_dateTimeEdit->setMaximumDateTime(ui->max_dateTimeEdit->dateTime());
    ui->max_dateTimeEdit->setMinimumDateTime(ui->min_dateTimeEdit->dateTime());
    connect(ui->min_dateTimeEdit,&QDateTimeEdit::dateTimeChanged,[=](){
        removeButton();
        this->minTime=ui->min_dateTimeEdit->dateTime();
        showButton();
    });
    connect(ui->max_dateTimeEdit,&QDateTimeEdit::dateTimeChanged,[=](){
        removeButton();
        this->maxTime=ui->max_dateTimeEdit->dateTime();
        showButton();
    });

    ui->choose_order->addItem("开始时间顺序");
    ui->choose_order->addItem("名字顺序");
    ui->choose_order->setCurrentIndex(0);
    connect(ui->choose_order,&QComboBox::currentIndexChanged,[=](){
        removeButton();
        if(ui->choose_order->currentIndex()==0){
            Task::sortTasks(currentAccount->get_taskList().begin(),currentAccount->get_taskList().end(),Task::stTime_ascending);
            showButton();
        }
        else{
            Task::sortTasks(currentAccount->get_taskList().begin(),currentAccount->get_taskList().end(),Task::taskName_ascending);
            showButton();
        }
    });

    ui->choose_category->setCurrentIndex(6);
    ui->choose_category->addItem("学习");
    ui->choose_category->addItem("娱乐");
    ui->choose_category->addItem("生活");
    ui->choose_category->addItem("工作");
    ui->choose_category->addItem("运动");
    ui->choose_category->addItem("其他");
    ui->choose_category->addItem("所有分类");
    connect(ui->choose_category,&QComboBox::currentIndexChanged,[=](){
        removeButton();
        this->chooseCtg=ui->choose_category->currentIndex();
        showButton();
    });

    ui->choose_priority->setCurrentIndex(3);
    ui->choose_priority->addItem("低");
    ui->choose_priority->addItem("中");
    ui->choose_priority->addItem("高");
    connect(ui->choose_priority,&QComboBox::currentIndexChanged,[=](){
        removeButton();
        this->choosePrio=ui->choose_priority->currentIndex();
        showButton();
    });

    connect(ui->auto_delete,&QCheckBox::stateChanged,[=](){
        if(ui->auto_delete->isChecked()){
            currentAccount->set_doneAndDel(true);
            del_done_task();
        }
        else{
            currentAccount->set_doneAndDel(false);
        }
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::auto_complete(){
    QStringList searched_tasks;
    for(int i=0;i<currentAccount->get_taskList().size();++i){
        searched_tasks<<currentAccount->get_taskList()[i]->get_taskName();
    }
    QCompleter *searchList=new QCompleter(searched_tasks,this);
    searchList->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_search->setCompleter(searchList);
}

void MainWindow::on_search_button_clicked(){
    QString getSearched=ui->lineEdit_search->text();
    bool findTask=false;
    int location=-1;
    for(int i=0;i<currentAccount->get_taskList().size();++i){
        if(getSearched==currentAccount->get_taskList()[i]->get_taskName()){
            findTask=true;
            location=i;
        }
    }
    if(findTask){
        task_info_window *task_info_page=new task_info_window(currentAccount->get_taskList()[location], this);
        task_info_page->show();
        ui->not_find_warning->hide();
    }
    else{
        ui->not_find_warning->setText("没有搜索到任务");
        ui->not_find_warning->show();
    }
}

void MainWindow::showButton(){
    if(chooseCtg==6||choosePrio==3){
        for(Task *task:currentAccount->get_taskList()){
            layout->addWidget(task->get_taskButton());
        }
    }
    else{
        for(Task *task:currentAccount->get_taskList()){
            if(task->get_stTime()>=minTime&&task->get_edTime()<=maxTime&&task->get_taskCtg()==chooseCtg&&task->get_taskPrio()==choosePrio){
                layout->addWidget(task->get_taskButton());
            }
        }
    }
}

void MainWindow::removeButton(){
    while(layout->count()){
        auto item=layout->takeAt(0);
    }
}

void MainWindow::on_add_task_button_clicked(){
    create_task_window *createPage=new create_task_window;
    createPage->show();
}

void MainWindow::del_done_task(){
    for(Task *task:currentAccount->get_taskList()){
        if(task->get_edTime()<=QDateTime::currentDateTime()){
            currentAccount->delTask(task);
        }
    }
}

void MainWindow::set_maxTime(QDateTime get_maxTime){
    maxTime=get_maxTime;
}

void MainWindow::set_minTime(QDateTime get_minTime){
    minTime=get_minTime;
}
