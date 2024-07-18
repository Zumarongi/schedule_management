#include "inprogress_rmdialog.h"
#include "ui_inprogress_rmdialog.h"
#include <QHBoxLayout>

void inProgress_rmDialog::setLayout(){
    this->setFixedSize(300,200);

    QHBoxLayout *layout = new QHBoxLayout;
    ui->label->move(50,70);
    ui->label->setFixedSize(60,30);
    ui->label->setAlignment(Qt::AlignCenter);
    layout->addWidget(ui->label);
    ui->taskName_label->setFixedSize(70,30);
    ui->taskName_label->move(115,70);
    ui->taskName_label->setAlignment(Qt::AlignCenter);
    layout->addWidget(ui->taskName_label);
    ui->label_2->setFixedSize(60,30);
    ui->label_2->move(190,70);
    ui->label_2->setAlignment(Qt::AlignCenter);
    layout->addWidget(ui->label_2);

    ui->OK_pushButton->setFixedSize(80,30);
    ui->OK_pushButton->move(110,140);
    ui->OK_pushButton->setStyleSheet("QPushButton{border-radius:8px;background-color:#148AFF;color:#FFFFFF;}");
}

inProgress_rmDialog::inProgress_rmDialog(Task *task,QWidget *parent)
    : currenTask(task)
    , QDialog(parent)
    , ui(new Ui::inProgress_rmDialog)
{
    ui->setupUi(this);

    setLayout();            //设置页面布局

    ui->taskName_label->setText(task->get_taskName());
}

inProgress_rmDialog::~inProgress_rmDialog()
{
    delete ui;
}

void inProgress_rmDialog::on_OK_pushButton_clicked()
{
    this->close();
}

