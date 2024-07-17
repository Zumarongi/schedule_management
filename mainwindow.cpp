#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "create_task_window.h"
#include "task_info_window.h"
#include <QHeaderView>

extern create_task_window *createTaskPage;
extern task_info_window *taskInfoPage;
extern void showWarning(QString text);

#define _FONT(s) QFont("Times New Roman", (s))
#define FONT _FONT(10)

void MainWindow::getInitTime()
{
    // minTime = QDateTime(QDate(1970, 1, 1), QTime(0, 0));
    // maxTime = QDateTime(QDate(2100, 1, 1), QTime(0, 0));
    minTime = QDateTime::currentDateTime();
    maxTime = minTime.addYears(1);
}

void MainWindow::setupInitValues()
{
    choosePrio = 0;
    chooseCtg = 0;
    getInitTime();
    ui->min_dateTimeEdit->setDateTime(minTime);
    ui->min_dateTimeEdit->setFont(FONT);
    ui->max_dateTimeEdit->setDateTime(maxTime);
    ui->max_dateTimeEdit->setFont(FONT);

    ui->choose_order->addItem("开始时间顺序");
    ui->choose_order->addItem("名字顺序");
    ui->choose_order->setCurrentIndex(0);
    ui->choose_order->setFont(FONT);

    ui->choose_category->addItem("所有分类");
    ui->choose_category->addItem("学习");
    ui->choose_category->addItem("娱乐");
    ui->choose_category->addItem("生活");
    ui->choose_category->addItem("工作");
    ui->choose_category->addItem("运动");
    ui->choose_category->addItem("其他");
    ui->choose_category->setCurrentIndex(0);
    ui->choose_category->setFont(FONT);

    ui->choose_priority->addItem("所有优先级");
    ui->choose_priority->addItem("低");
    ui->choose_priority->addItem("中");
    ui->choose_priority->addItem("高");
    ui->choose_priority->setCurrentIndex(0);
    ui->choose_priority->setFont(FONT);


    ui->lineEdit_search->setFont(FONT);
    ui->label_from->setFont(FONT);
    ui->label_to->setFont(FONT);
    ui->add_task_button->setFont(FONT);
    ui->auto_delete->setFont(FONT);
    ui->not_find_warning->setFont(FONT);
    ui->not_find_warning->setStyleSheet("color: red;");

    //搜索框自动补全
    connect(ui->lineEdit_search,&QLineEdit::textChanged,this,&MainWindow::auto_complete);

    ui->auto_delete->setCheckable(true);
    ui->auto_delete->setChecked(currentAccount->get_doneAndDel());

    if(currentAccount->get_doneAndDel())                //自动删除
        del_done_task();
}

void MainWindow::setupMainLayout()
{
    this->setFixedSize(800,600);
    this->setWindowTitle("主页");

    mainLayout = new QVBoxLayout;

    QHBoxLayout *hLayout = new QHBoxLayout;
    {
        ui->lineEdit_search->setFixedSize(500,30);
        ui->lineEdit_search->move(50,25);
        ui->lineEdit_search->setStyleSheet("QLineEdit{border-radius:15px;}");
        hLayout->addWidget(ui->lineEdit_search);

        QIcon icon;
        icon.addFile((ROOTDIR+"/images/magnifying glass").c_str());
        ui->search_button->setFixedSize(50,30);
        ui->search_button->move(500,25);
        ui->search_button->setStyleSheet("QPushButton{border-radius:15px;background-color:#148AFF;color:#FFFFFF;}");
        ui->search_button->setIcon(icon);
        hLayout->addWidget(ui->search_button);

        ui->add_task_button->setFixedSize(80,30);
        ui->add_task_button->move(600,25);
        ui->add_task_button->setStyleSheet("QPushButton{border-radius:15px;background-color:#148AFF;color:#FFFFFF;}");
        hLayout->addWidget(ui->add_task_button);

        ui->not_find_warning->setStyleSheet("QLabel{background-color:#FFFFFF;}");
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

        ui->choose_order->setFixedSize(100, 30);
        ui->choose_order->move(395, 80);
        hLayout->addWidget(ui->choose_order);

        QIcon icon;
        icon.addFile((ROOTDIR+"/images/arrow").c_str());
        ui->toggle_button->setFixedSize(20,30);
        ui->toggle_button->move(500,80);
        ui->toggle_button->setIcon(icon);
        hLayout->addWidget(ui->toggle_button);

        ui->choose_priority->setFixedSize(90, 30);
        ui->choose_priority->move(525, 80);
        hLayout->addWidget(ui->choose_priority);

        ui->choose_category->setFixedSize(80, 30);
        ui->choose_category->move(620, 80);
        hLayout->addWidget(ui->choose_category);
    }
    mainLayout->addLayout(hLayout);

    ui->scrollArea->setFixedSize(780,400);
    ui->scrollArea->move(10,125);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setWidgetResizable(true);
    taskFiltering(), taskOrdering();
    setupScrollLayout();

    this->setLayout(mainLayout);

    ui->auto_delete->setFixedSize(100,20);
    ui->auto_delete->move(30,550);
}

void MainWindow::setupRemindThread()
{
    arrving_remind=new remindThread();
    arrving_remind->moveToThread(&m_thread);
    connect(&m_thread,&QThread::started,arrving_remind,&remindThread::onCreateTimer);
    connect(&m_thread,&QThread::finished,arrving_remind,&QObject::deleteLater);
    m_thread.start();
}

void MainWindow::taskFiltering()
{
    taskOrder.clear();
    for (auto task: currentAccount->get_taskList())
        if ((task->get_stTime() >= minTime && task->get_stTime() <= maxTime) &&
            (task->get_taskCtg() == chooseCtg || chooseCtg == 0) &&
            (task->get_taskPrio() == choosePrio || choosePrio == 0) &&
            task->get_taskName().startsWith(ui->lineEdit_search->text()))
                taskOrder.push_back(task);
}

void MainWindow::taskOrdering()
{
    bool (*cmp)(const Task *, const Task *) = Task::stTime_ascending;
    if(ui->choose_order->currentIndex()==0){
        if(isPosSeq) cmp = Task::stTime_ascending;
        else cmp = Task::stTime_descending;
    }
    else{
        if(isPosSeq) cmp = Task::taskName_ascending;
        else cmp = Task::taskName_descending;
    }
    Task::sortTasks(taskOrder.begin(), taskOrder.end(), cmp);
}

void MainWindow::setupScrollLayout()
{
    scrollLayout = new QTableWidget(taskOrder.size(), 5);

    scrollLayout->setHorizontalHeaderLabels(QStringList()<<"任务名称"<<"优先级"<<"开始时间 —— 结束时间"<<"地点"<<"分类");
    scrollLayout->verticalHeader()->setVisible(false);
    scrollLayout->horizontalHeader()->setVisible(true);
    // scrollLayout->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    scrollLayout->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    scrollLayout->resizeColumnsToContents();

    scrollLayout->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    scrollLayout->setSelectionBehavior(QAbstractItemView::SelectRows);
    scrollLayout->setEditTriggers(QAbstractItemView::NoEditTriggers);

    scrollLayout->setFont(FONT);

    scrollLayout->setColumnWidth(0, 80);
    scrollLayout->setColumnWidth(1, 75);
    scrollLayout->setColumnWidth(2, 370);
    scrollLayout->setColumnWidth(3, 170);
    scrollLayout->setColumnWidth(4, 80);

    scrollLayout->setStyleSheet("QTableWidget { background-color: #f0f0f0; }"
                                "QTableWidget::item:hover { background-color: #e0e0e0; }" // 鼠标悬浮时的背景色
                                "QTableWidget::item:selected { background-color: #a0a0a0; }"); // 选中项的背景色
    int row = 0;
    for (auto task: taskOrder)
    {
        int alpha = 0;
        switch ((int)(task->get_taskPrio()))
        {
        case 1:
            alpha = 60; break;
        case 2:
            alpha = 105; break;
        case 3:
            alpha = 180; break;
        }
        QString alphaStr = QString::fromStdString(std::to_string(alpha));

        QPushButton *taskButton = new QPushButton(task->get_taskName(), this);
        taskButton->setFont(FONT);
        taskButton->setFixedWidth(80);
        taskButton->setStyleSheet("QPushButton{ border-radius: 0px; background-color: rgba(255, 0, 0, " + alphaStr + "); }");
        connect(taskButton, &QPushButton::clicked, [=](){
            taskInfoPage = new task_info_window(task);
            taskInfoPage->show();
            this->close();
        });
        scrollLayout->setCellWidget(row, 0, taskButton);

        taskButton = new QPushButton(toQString(task->get_taskPrio()), this);
        taskButton->setFont(FONT);
        taskButton->setStyleSheet("QPushButton{ border-radius: 0px; background-color: rgba(255, 0, 0, " + alphaStr + "); }");
        connect(taskButton, &QPushButton::clicked, [=](){
            taskInfoPage = new task_info_window(task);
            taskInfoPage->show();
            this->close();
        });
        scrollLayout->setCellWidget(row, 1, taskButton);

        taskButton = new QPushButton(task->get_stTime().toString("yyyy-MM-dd hh:mm") + QString::fromStdString("——") + task->get_edTime().toString("yyyy-MM-dd hh:mm"));
        taskButton->setFont(FONT);
        taskButton->setStyleSheet("QPushButton{ border-radius: 0px; background-color: rgba(255, 0, 0, " + alphaStr + "); }");
        connect(taskButton, &QPushButton::clicked, [=](){
            taskInfoPage = new task_info_window(task);
            taskInfoPage->show();
            this->close();
        });
        scrollLayout->setCellWidget(row, 2, taskButton);

        taskButton = new QPushButton(task->get_taskLoc());
        taskButton->setFont(FONT);
        taskButton->setStyleSheet("QPushButton{ border-radius: 0px; background-color: rgba(255, 0, 0, " + alphaStr + "); }");
        connect(taskButton, &QPushButton::clicked, [=](){
            taskInfoPage = new task_info_window(task);
            taskInfoPage->show();
            this->close();
        });
        scrollLayout->setCellWidget(row, 3, taskButton);

        taskButton = new QPushButton(Task::toCtgQString(task->get_taskCtg()));
        taskButton->setFont(FONT);
        QColor taskCtgColor;
        QString ctgcolorStr = "";
        switch (task->get_taskCtg())
        {
        case 1:
            ctgcolorStr = "0, 204, 0, "; break;
        case 2:
            ctgcolorStr = "0, 204, 204, "; break;
        case 3:
            ctgcolorStr = "51, 102, 204, "; break;
        case 4:
            ctgcolorStr = "102, 0, 204, "; break;
        case 5:
            ctgcolorStr = "204, 51, 102, "; break;
        case 6:
            ctgcolorStr = "102, 102, 102, "; break;
        }
        taskButton->setStyleSheet("QPushButton{ border-radius: 0px; background-color: rgba(" + ctgcolorStr + alphaStr + "); }");
        connect(taskButton, &QPushButton::clicked, [=](){
            taskInfoPage = new task_info_window(task);
            taskInfoPage->show();
            this->close();
        });
        scrollLayout->setCellWidget(row, 4, taskButton);
        row ++;
    }
    ui->scrollArea->setWidget(scrollLayout);
}

void MainWindow::removeTaskButton()
{
    int rows = scrollLayout->rowCount();
    int cols = scrollLayout->columnCount();
    for (int i = 0; i < rows; i ++)
    {
        for (int j = 0; j < cols; j ++)
        {
            QWidget *widget = scrollLayout->cellWidget(0, j);
            scrollLayout->removeCellWidget(0, j);
            delete widget;
        }
        scrollLayout->removeRow(0);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupRemindThread(); // 初始化提醒线程
    setupInitValues(); // 各变量以及显示值的初始化
    setupMainLayout(); // 设置页面布局

    // connect reorder信号
    connect(this, &MainWindow::reorder, [=](){
        removeTaskButton();
        taskFiltering(), taskOrdering();
        setupScrollLayout();
    });

    connect(arrving_remind, &remindThread::reorder, [=](){
        removeTaskButton();
        taskFiltering(), taskOrdering();
        setupScrollLayout();
    });
    connect(arrving_remind,&remindThread::showRemind,this,&MainWindow::create_remind_Page);
    connect(arrving_remind,&remindThread::inProgress,this,&MainWindow::inProgress_remind_Page);
    // connect(this,&MainWindow::inProgress,this,&MainWindow::inProgress_remind_Page);
}

MainWindow::~MainWindow()
{
    m_thread.quit();
    m_thread.wait();
    currentAccount->saveToFile();
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
    emit reorder();
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
    currentAccount->saveToFile();
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

void MainWindow::on_auto_delete_stateChanged(int arg1)
{
    currentAccount->set_doneAndDel(ui->auto_delete->isChecked());
    if (ui->auto_delete->isChecked())
        del_done_task();
}

void MainWindow::on_lineEdit_search_textChanged(const QString &arg1)
{
    ui->not_find_warning->hide();
    emit reorder();
}

void MainWindow::auto_complete(){
    searched_tasks.clear();
    for (Task * task: currentAccount->get_taskList())
        searched_tasks.append(task->get_taskName());
    QCompleter *searchList=new QCompleter(searched_tasks,this);
    searchList->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_search->setCompleter(searchList);
}

void MainWindow::create_remind_Page(Task *task){
    remindPage=new remindDialog(task);
    remindPage->show();
}

void MainWindow::inProgress_remind_Page(Task *task){
    inProgress_rmPage=new inProgress_rmDialog(task);
    inProgress_rmPage->show();
}

void MainWindow::on_toggle_button_clicked()
{
    isPosSeq=!isPosSeq;
    if(isPosSeq){
        QIcon icon;
        icon.addFile((ROOTDIR+"/images/arrow").c_str());
        ui->toggle_button->setIcon(icon);
    }
    else{
        QIcon icon;
        icon.addFile((ROOTDIR+"/images/arrow2").c_str());
        ui->toggle_button->setIcon(icon);
    }
    emit reorder();
}

