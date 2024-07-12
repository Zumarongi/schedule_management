#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(Account *getAccount,QWidget *parent)
    : currentAccount(getAccount)
    , QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);
    ui->lineEdit_search->setFixedSize(500,30);
    ui->lineEdit_search->move(150,20);
    ui->lineEdit_search->setStyleSheet("QLineEdit{border-radius:15px;}");
    ui->search_button->setFixedSize(50,30);
    ui->search_button->move(600,20);
    ui->search_button->setStyleSheet("QPushButton{border-radius:15px;background-color:#148AFF;}");
    ui->add_task_button->setFixedSize(40,40);
    ui->add_task_button->move(700,15);
    ui->add_task_button->setStyleSheet("QPushButton{border-radius:20px;background-color:#148AFF;}");
    ui->not_find_warning->hide();
    ui->not_find_warning->setFixedSize(450,20);
    ui->not_find_warning->move(165,50);
    ui->not_find_warning->setStyleSheet("QLabel{background-color:#FFFFFF;}");
    ui->scrollArea->setFixedSize(790,520);
    ui->scrollArea->move(10,80);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setWidgetResizable(true);
    QWidget *contentWidget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(contentWidget);
    ui->scrollArea->setWidget(contentWidget);
    layout->setContentsMargins(35,5,35,5);
    /*QPushButton *button=new QPushButton;
    button->setFixedSize(700,40);
    layout->addWidget(button);
    QPushButton *button1=new QPushButton;
    button1->setFixedSize(700,40);
    layout->addWidget(button1);
    */
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
    for(int i=0;currentAccount->taskList.size();++i){
        if(getSearched==currentAccount->taskList[i]->get_taskName()){
            findTask=true;
            location=i;
        }
    }
    if(findTask){
        task_info_window *task_info_page=new task_info_window(currentAccount->taskList[location]);
        task_info_page->show();
        ui->not_find_warning->hide();
    }
    else{
        ui->not_find_warning->setText("没有搜索到任务");
        ui->not_find_warning->show();
    }
}
