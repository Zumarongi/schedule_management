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
    ui->name_order_button->setFixedSize(80,20);
    ui->name_order_button->move(10,5);
    ui->time_order_button->setFixedSize(150,20);
    ui->time_order_button->move(100,5);
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
    ui->scrollArea->setFixedSize(790,520);
    ui->scrollArea->move(10,80);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setWidgetResizable(true);
    contentWidget = new QWidget;
    layout = new QVBoxLayout(contentWidget);                //记得调整间距
    ui->scrollArea->setWidget(contentWidget);
    layout->setContentsMargins(35,5,35,5);
    for(int i=0;i<currentAccount->taskList.size();++i){
        taskOrder[i]=currentAccount->taskList[i];
    }
    /*QPushButton *button=new QPushButton;
    button->setFixedSize(700,40);
    layout->addWidget(button);
    QPushButton *button1=new QPushButton;
    button1->setFixedSize(700,40);
    layout->addWidget(button1);
    */
    if(currentAccount->doneAndDel) del_done_task();
    showButton();

    QMenu *main_menu =new QMenu();
    main_menu->addAction("时间段",[=](){
        get_time_range *getTimePage=new get_time_range;
        getTimePage->show();
        connect(getTimePage,&get_time_range::done_change,[=](){
            removeButton();
            taskOrder.clear();
            int i=0,j=0;
            while(i<currentAccount->taskList.size()){
                if(currentAccount->taskList[i]->get_stTime()>=currentAccount->minTime&&currentAccount->taskList[i]->get_edTime()<=currentAccount->maxTime){
                    taskOrder[j]=currentAccount->taskList[i];
                    ++j;
                }
                ++i;
            }
            showButton();
        });
    });

    //QMenu *sub_time_menu=new QMenu("时间段");
    QMenu *sub_prio_menu=new QMenu("优先级");
    QMenu *sub_ctg_menu=new QMenu("分类");
    //main_menu->addMenu(sub_time_menu);
    main_menu->addMenu(sub_prio_menu);
    main_menu->addMenu(sub_ctg_menu);                    //排序方式

    sub_prio_menu->addAction("高",[=](){
        removeButton();
        taskOrder.clear();
        int i=0,j=0;
        while(i<currentAccount->taskList.size()){
            if(currentAccount->taskList[i]->get_taskPrio()==2){
                taskOrder[j]=currentAccount->taskList[i];
                ++j;
            }
            ++i;
        }
        showButton();
    });

    sub_prio_menu->addAction("中",[=](){
        removeButton();
        taskOrder.clear();
        int i=0,j=0;
        while(i<currentAccount->taskList.size()){
            if(currentAccount->taskList[i]->get_taskPrio()==1){
                taskOrder[j]=currentAccount->taskList[i];
                ++j;
            }
            ++i;
        }
        showButton();
    });

    sub_prio_menu->addAction("低",[=](){
        removeButton();
        taskOrder.clear();
        int i=0,j=0;
        while(i<currentAccount->taskList.size()){
            if(currentAccount->taskList[i]->get_taskPrio()==0){
                taskOrder[j]=currentAccount->taskList[i];
                ++j;
            }
            ++i;
        }
        showButton();
    });

    sub_ctg_menu->addAction("学习",[=](){
        removeButton();
        taskOrder.clear();
        int i=0,j=0;
        while(i<currentAccount->taskList.size()){
            if(currentAccount->taskList[i]->get_taskCtg()==0){
                taskOrder[j]=currentAccount->taskList[i];
                ++j;
            }
            ++i;
        }
        showButton();
    });

    sub_ctg_menu->addAction("娱乐",[=](){
        removeButton();
        taskOrder.clear();
        int i=0,j=0;
        while(i<currentAccount->taskList.size()){
            if(currentAccount->taskList[i]->get_taskCtg()==1){
                taskOrder[j]=currentAccount->taskList[i];
                ++j;
            }
            ++i;
        }
        showButton();
    });

    sub_ctg_menu->addAction("生活",[=](){
        removeButton();
        taskOrder.clear();
        int i=0,j=0;
        while(i<currentAccount->taskList.size()){
            if(currentAccount->taskList[i]->get_taskCtg()==2){
                taskOrder[j]=currentAccount->taskList[i];
                ++j;
            }
            ++i;
        }
        showButton();
    });

    sub_ctg_menu->addAction("工作",[=](){
        removeButton();
        taskOrder.clear();
        int i=0,j=0;
        while(i<currentAccount->taskList.size()){
            if(currentAccount->taskList[i]->get_taskCtg()==3){
                taskOrder[j]=currentAccount->taskList[i];
                ++j;
            }
            ++i;
        }
        showButton();
    });

    sub_ctg_menu->addAction("运动",[=](){
        removeButton();
        taskOrder.clear();
        int i=0,j=0;
        while(i<currentAccount->taskList.size()){
            if(currentAccount->taskList[i]->get_taskCtg()==4){
                taskOrder[j]=currentAccount->taskList[i];
                ++j;
            }
            ++i;
        }
        showButton();
    });

    sub_ctg_menu->addAction("其他",[=](){
        removeButton();
        taskOrder.clear();
        int i=0,j=0;
        while(i<currentAccount->taskList.size()){
            if(currentAccount->taskList[i]->get_taskCtg()==5){
                taskOrder[j]=currentAccount->taskList[i];
                ++j;
            }
            ++i;
        }
        showButton();
    });

    ui->change_order_button->setFixedSize(60,25);
    ui->change_order_button->move(50,55);
    connect(ui->change_order_button,&QPushButton::clicked,[=](){
        QPoint pos = ui->change_order_button->mapToGlobal(QPoint(0, ui->change_order_button->height()));
        main_menu->exec(pos);
    });

    connect(ui->auto_delete,&QCheckBox::stateChanged,[=](){
        if(ui->auto_delete->isChecked()){
            currentAccount->doneAndDel=true;
            del_done_task();
        }
        else{
            currentAccount->doneAndDel=false;
        }
    });

    connect(ui->time_order_button,&QRadioButton::clicked,[=](){
        if(ui->time_order_button->isChecked()){
            removeButton();
            currentAccount->sortTask(Task::stTime_ascending);
            taskOrder.clear();
            currentAccount->sortTask(taskOrder,Task::stTime_ascending);
            showButton();
        }
    });

    connect(ui->name_order_button,&QRadioButton::clicked,[=](){
        if(ui->name_order_button->isChecked()){
            removeButton();
            currentAccount->sortTask(Task::taskName_ascending);
            taskOrder.clear();
            currentAccount->sortTask(currentAccount->taskList,Task::taskName_ascending);
            currentAccount->sortTask(taskOrder,Task::stTime_ascending);
            showButton();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::auto_complete(){
    QStringList searched_tasks;
    for(int i=0;i<currentAccount->taskList.size();++i){
        searched_tasks<<currentAccount->taskList[i]->get_taskName();
    }
    QCompleter *searchList=new QCompleter(searched_tasks,this);
    searchList->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_search->setCompleter(searchList);
}

void MainWindow::on_search_button_clicked(){
    QString getSearched=ui->lineEdit_search->text();
    bool findTask=false;
    int location=-1;
    for(int i=0;i<currentAccount->taskList.size();++i){
        if(getSearched==currentAccount->taskList[i]->get_taskName()){
            findTask=true;
            location=i;
        }
    }
    if(findTask){
        task_info_window *task_info_page=new task_info_window(currentAccount->taskList[location], this);
        task_info_page->show();
        ui->not_find_warning->hide();
    }
    else{
        ui->not_find_warning->setText("没有搜索到任务");
        ui->not_find_warning->show();
    }
}

void MainWindow::showButton(){
    for(int i=0;i<taskOrder.size();++i){
        layout->addWidget(taskOrder[i]->get_taskButton());
    }
}

void MainWindow::removeButton(){
    for(int i=0;i<taskOrder.size();++i){
        layout->removeWidget(taskOrder[i]->get_taskButton());
    }
}

void MainWindow::on_add_task_button_clicked(){
    create_task_window *createPage=new create_task_window;
    createPage->show();
}

void MainWindow::del_done_task(){
    for (int i = 0; i < currentAccount->taskList.size(); ++i) {
        //if任务过时，删除
    }
}
