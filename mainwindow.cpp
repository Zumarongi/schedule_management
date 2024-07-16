#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "create_task_window.h"
#include "task_info_window.h"
#include "remindthread.h"

extern create_task_window *createTaskPage;
extern task_info_window *taskInfoPage;

void MainWindow::setupInitValues()
{
    choosePrio = 0;
    chooseCtg = 0;
    minTime = QDateTime(QDate(1970, 1, 1), QTime(0, 0)); // 设置为指定日期和时间
    maxTime = QDateTime(QDate(2100, 1, 1), QTime(0, 0));
    ui->min_dateTimeEdit->setDateTime(minTime);
    ui->max_dateTimeEdit->setDateTime(maxTime);

    ui->choose_order->addItem("开始时间顺序");
    ui->choose_order->addItem("名字顺序");
    ui->choose_order->setCurrentIndex(0);

    ui->choose_category->addItem("所有分类");
    ui->choose_category->addItem("学习");
    ui->choose_category->addItem("娱乐");
    ui->choose_category->addItem("生活");
    ui->choose_category->addItem("工作");
    ui->choose_category->addItem("运动");
    ui->choose_category->addItem("其他");
    ui->choose_category->setCurrentIndex(0);

    ui->choose_priority->addItem("所有优先级");
    ui->choose_priority->addItem("低");
    ui->choose_priority->addItem("中");
    ui->choose_priority->addItem("高");
    ui->choose_priority->setCurrentIndex(0);

    QStringList searched_tasks;
    for (Task *task: currentAccount->get_taskList())
        searched_tasks.append(task->get_taskName());
    QCompleter *searchList=new QCompleter(searched_tasks,this);
    searchList->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_search->setCompleter(searchList);
}

void MainWindow::setupMainLayout()
{
    this->setFixedSize(800,600);
    mainLayout = new QVBoxLayout;

    QHBoxLayout *hLayout = new QHBoxLayout;
    {
        ui->lineEdit_search->setFixedSize(500,30);
        ui->lineEdit_search->move(50,25);
        ui->lineEdit_search->setStyleSheet("QLineEdit{border-radius:15px;}");
        hLayout->addWidget(ui->lineEdit_search);

        ui->search_button->setFixedSize(50,30);
        ui->search_button->move(500,25);
        ui->search_button->setStyleSheet("QPushButton{border-radius:15px;background-color:#148AFF;}");
        hLayout->addWidget(ui->search_button);

        ui->add_task_button->setFixedSize(80,30);
        ui->add_task_button->move(600,25);
        ui->add_task_button->setStyleSheet("QPushButton{border-radius:15px;background-color:#148AFF;}");
        hLayout->addWidget(ui->add_task_button);
    }
    mainLayout->addLayout(hLayout);

    ui->not_find_warning->hide();
    ui->not_find_warning->setFixedSize(450,20);
    ui->not_find_warning->move(70,55);
    ui->not_find_warning->setAlignment(Qt::AlignLeft);
    ui->not_find_warning->setStyleSheet("QLabel{border-radius:10px;}");
    mainLayout->addWidget(ui->not_find_warning);

    hLayout = new QHBoxLayout;
    {
        ui->label_from->setFixedSize(20, 30);
        ui->label_from->move(10, 80);
        ui->label_from->setAlignment(Qt::AlignCenter);
        hLayout->addWidget(ui->label_from);

        ui->min_dateTimeEdit->setFixedSize(170, 30);
        ui->min_dateTimeEdit->move(30, 80);
        hLayout->addWidget(ui->min_dateTimeEdit);

        ui->label_to->setFixedSize(20, 30);
        ui->label_to->move(200, 80);
        ui->label_to->setAlignment(Qt::AlignCenter);
        hLayout->addWidget(ui->label_to);

        ui->max_dateTimeEdit->setFixedSize(170, 30);
        ui->max_dateTimeEdit->move(220, 80);
        hLayout->addWidget(ui->max_dateTimeEdit);

        ui->choose_order->setFixedSize(120, 30);
        ui->choose_order->move(395, 80);
        hLayout->addWidget(ui->choose_order);

        ui->choose_priority->setFixedSize(120, 30);
        ui->choose_priority->move(520, 80);
        hLayout->addWidget(ui->choose_priority);

        ui->choose_category->setFixedSize(120, 30);
        ui->choose_category->move(645, 80);
        hLayout->addWidget(ui->choose_category);
    }
    mainLayout->addLayout(hLayout);

    ui->scrollArea->setFixedSize(790,400);
    ui->scrollArea->move(10,125);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setWidgetResizable(true);
    taskFiltering(), taskOrdering();
    setupTaskButton();

    this->setLayout(mainLayout);

    ui->auto_delete->setFixedSize(100,20);
    ui->auto_delete->move(30,550);
}

void MainWindow::setupRemindThread()
{
    remindThread * arrving_remind=new remindThread;
    arrving_remind->start();
}

void MainWindow::taskFiltering()
{
    currentAccount->printTask();
    qDebug() << minTime;
    qDebug() << maxTime;
    qDebug() << choosePrio;
    qDebug() << chooseCtg;
    taskOrder.clear();
    for (auto task: currentAccount->get_taskList())
    {
        qDebug() << task->get_taskId() << "\t" << task->get_taskName() << "\t" << task->get_stTime() << "\t" << task->get_edTime() << "\t" << task->get_taskPrio() << "\t" << task->get_taskCtg();
        if ((task->get_stTime() >= minTime && task->get_stTime() <= maxTime) && (task->get_taskCtg() == chooseCtg || chooseCtg == 0) && (task->get_taskPrio() == choosePrio || choosePrio == 0))
            taskOrder.push_back(task);
    }
}

void MainWindow::taskOrdering()
{
    bool (*cmp)(const Task *, const Task *) = Task::stTime_ascending;
    switch (ui->choose_order->currentIndex())
    {
    case 0:
        cmp = Task::stTime_ascending; break;
    case 1:
        cmp = Task::taskName_ascending; break;
    }
    Task::sortTasks(taskOrder.begin(), taskOrder.end(), cmp);
}

void MainWindow::setupTaskButton()
{
    scrollLayout = new QVBoxLayout;
    scrollLayout->setContentsMargins(35, 5, 35, 5);
    qDebug() << "showLayout(): printing taskOrder";
    for (auto task: taskOrder)
    {
        qDebug() << task->get_taskId() << "\t" << task->get_taskName();
        QPushButton *taskButton = new QPushButton(task->get_taskName(), this);
        taskButton->setFixedSize(700, 40);
        taskButton->setStyleSheet("QPushButton{border-radius:5px;background-color:#148AFF;}");
        connect(taskButton, &QPushButton::clicked, [=](){
            taskInfoPage = new task_info_window(task);
            taskInfoPage->show();
            this->close();
        });
        scrollLayout->addWidget(taskButton);
    }
    ui->scrollArea->setLayout(scrollLayout);
    mainLayout->addWidget(ui->scrollArea);
}

void MainWindow::removeTaskButton()
{
    QObjectList buttonList = scrollLayout->children();
    for (int i = 0; i < buttonList.length(); i ++)
    {
        QPushButton *taskButton = qobject_cast<QPushButton *>(buttonList.at(i));
        taskButton->setParent(NULL);
        scrollLayout->removeWidget(taskButton);
        // scrollLayout->takeAt(0);
        delete taskButton;
    }
    mainLayout->removeWidget(ui->scrollArea);
    delete scrollLayout;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupInitValues(); // 各变量以及显示值的初始化
    setupMainLayout(); // 设置页面布局
    setupRemindThread(); // 初始化提醒线程

    // connect reorder信号
    connect(this, &MainWindow::reorder, [=](){
        removeTaskButton();
        taskFiltering(), taskOrdering();
        setupTaskButton();
    });

    if(currentAccount->get_doneAndDel())
        del_done_task();

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
    delete ui->lineEdit_search->completer();
    delete mainLayout;
    delete scrollLayout;
    delete ui;
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

void MainWindow::closeEvent(QCloseEvent *event)
{
    Account::saveAccountList();
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

void MainWindow::on_add_task_button_clicked(){
    delete createTaskPage;
    createTaskPage = new create_task_window;
    createTaskPage->show();
    this->close();
}

void MainWindow::on_min_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    minTime = dateTime;
    emit reorder();
}

void MainWindow::on_max_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    maxTime = dateTime;
    emit reorder();
}

void MainWindow::on_choose_order_currentIndexChanged(int index) { emit reorder(); }

void MainWindow::on_choose_priority_currentIndexChanged(int index)
{
    choosePrio = index;
    emit reorder();
}

void MainWindow::on_choose_category_currentIndexChanged(int index)
{
    chooseCtg = index;
    emit reorder();
}

