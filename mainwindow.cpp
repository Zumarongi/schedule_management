#include "mainwindow.h"
#include "./ui_mainwindow.h"

create_task_window *createTaskPage;
task_info_window *taskInfoPage;

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

    taskOrder=currentAccount->get_taskList();

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
    ui->scrollArea->setFixedSize(790,400);
    //ui->scrollArea->move(10,80);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setWidgetResizable(true);
    contentWidget = new QWidget;
    layout = new QVBoxLayout(contentWidget);                //记得调整间距
    ui->scrollArea->setWidget(contentWidget);
    layout->setContentsMargins(35,5,35,5);
    // QPushButton *button=new QPushButton;
    // button->setFixedSize(700,200);
    // layout->addWidget(button);
    // QPushButton *button1=new QPushButton;
    // button1->setFixedSize(700,200);
    // layout->addWidget(button1);

    taskOrder = currentAccount->get_taskList();

    if(currentAccount->get_doneAndDel()) del_done_task();

    QStringList searched_tasks;
    for (Task * task: currentAccount->get_taskList())
        searched_tasks.append(task->get_taskName());
    QCompleter *searchList=new QCompleter(searched_tasks,this);
    searchList->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_search->setCompleter(searchList);

    choosePrio=0;
    chooseCtg=0;
    maxTime=QDateTime::currentDateTime();
    minTime = QDateTime(QDate(1970, 0, 0), QTime(0, 0)); // 设置为指定日期和时间

    showButton();

    connect(ui->min_dateTimeEdit, &QDateTimeEdit::dateTimeChanged, [=](){
        this->minTime=ui->min_dateTimeEdit->dateTime();
        emit reorder();
    });
    connect(ui->max_dateTimeEdit, &QDateTimeEdit::dateTimeChanged, [=](){
        this->maxTime=ui->max_dateTimeEdit->dateTime();
        emit reorder();
    });

    ui->choose_order->addItem("开始时间顺序");
    ui->choose_order->addItem("名字顺序");
    ui->choose_order->setCurrentIndex(0);
    connect(ui->choose_order, &QComboBox::currentIndexChanged, [=](){
        //
        emit reorder();
    });

    ui->choose_category->setCurrentIndex(0);
    ui->choose_category->addItem("所有分类");
    ui->choose_category->addItem("学习");
    ui->choose_category->addItem("娱乐");
    ui->choose_category->addItem("生活");
    ui->choose_category->addItem("工作");
    ui->choose_category->addItem("运动");
    ui->choose_category->addItem("其他");
    connect(ui->choose_category, &QComboBox::currentIndexChanged, [=](){
        this->chooseCtg=ui->choose_category->currentIndex();
        emit reorder();
    });

    ui->choose_priority->setCurrentIndex(0);
    ui->choose_priority->addItem("所有优先级");
    ui->choose_priority->addItem("低");
    ui->choose_priority->addItem("中");
    ui->choose_priority->addItem("高");
    connect(ui->choose_priority, &QComboBox::currentIndexChanged, [=](){
        this->choosePrio=ui->choose_priority->currentIndex();
        emit reorder();
    });

    // connect(createTaskPage, &create_task_window::done_creation, [=](){emit reorder();});
    // connect(taskInfoPage, &task_info_window::done_modification, [=](){emit reorder();});

    connect(this, &MainWindow::reorder, [=](){
        currentAccount->printTask();
        removeButton();
        // removeHLayout();
        taskOrder.clear();
        for (auto task: currentAccount->get_taskList())
            if ((task->get_stTime() >= minTime && task->get_edTime() <= maxTime)
             && (task->get_taskCtg()==chooseCtg || chooseCtg == 0)
             && (task->get_taskPrio()==choosePrio || choosePrio == 0))
                taskOrder.push_back(task);
        bool (*cmp)(const Task *, const Task *);
        switch (ui->choose_order->currentIndex())
        {
        case 0:
            cmp = Task::stTime_ascending; break;
        case 1:
            cmp = Task::taskName_ascending; break;
        default:
            cmp = Task::stTime_ascending;
        }
        Task::sortTasks(taskOrder.begin(), taskOrder.end(), cmp);
        showButton();
        // showHLayout();
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
    Account::saveAccountList();
    delete currentAccount;
    delete createTaskPage;
    delete taskInfoPage;
    for(Task *task:taskOrder){
        delete task;
    }
    delete contentWidget;
    delete layout;
    delete ui;
}

void MainWindow::on_search_button_clicked(){
    QString getSearched=ui->lineEdit_search->text();
    bool findTask=false;
    Task *taskSearched;
    for (auto task: currentAccount->get_taskList())
        if(getSearched==task->get_taskName())
        {
            findTask=true;
            taskSearched=task;
        }
    if(findTask){
        delete taskInfoPage;
        taskInfoPage = new task_info_window(taskSearched);
        this->close();
        taskInfoPage->show();
        ui->not_find_warning->hide();
    }
    else{
        ui->not_find_warning->setText("没有搜索到任务");
        ui->not_find_warning->show();
    }
}

void MainWindow::showButton(){
    for(Task *task: taskOrder)
        layout->addWidget(task->get_taskButton());
}

void MainWindow::removeButton(){
    for(Task *task:taskOrder){
        layout->removeWidget(task->get_taskButton());
    }
}

void MainWindow::removeHLayout()
{
}

void MainWindow::showHLayout()
{

}

void MainWindow::on_add_task_button_clicked(){
    delete createTaskPage;
    createTaskPage = new create_task_window;
    createTaskPage->show();
    this->close();
}

void MainWindow::del_done_task(){
    for (auto task: currentAccount->get_taskList()){
        if(task->get_edTime()<=QDateTime::currentDateTime()){
            currentAccount->delTask(task);
        }
    }
}

QDateTime MainWindow::get_minTime() const { return minTime; }

QDateTime MainWindow::get_maxTime() const { return maxTime; }

void MainWindow::set_minTime(QDateTime new_minTime) { minTime = new_minTime; }

void MainWindow::set_maxTime(QDateTime new_maxTime) { maxTime = new_maxTime; }

void MainWindow::showEvent(QShowEvent *event)
{
    emit reorder();
}
