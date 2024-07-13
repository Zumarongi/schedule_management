#include "task_info_window.h"
#include "ui_task_info_window.h"
#include "mainwindow.h"
#include "timeformat.h"

using namespace timeformat;

extern MainWindow *mainPage;

task_info_window::task_info_window(Task *task, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::task_info_window)
{
    ui->setupUi(this);

    connect(ui->editButton_taskName, &QPushButton::clicked, [=](){
        ui->lineEdit_taskName->setReadOnly(false);
    });

    connect(ui->pushButton_saveChanges, &QPushButton::clicked, [=](){

        if (ui->lineEdit_taskName->isModified())
            task->set_taskName(ui->lineEdit_taskName->text());

        if (ui->dateTimeEdit_stTime->isWindowModified())
            task->set_stTime(toTime_t(ui->dateTimeEdit_stTime->dateTime()));

        if (ui->dateTimeEdit_edTime->isWindowModified())
            task->set_edTime(toTime_t(ui->dateTimeEdit_edTime->dateTime()));

        if (ui->lineEdit_rmTime_h->isModified() || ui->lineEdit_rmTime_m->isModified())
            task->set_rmTime(toTime_tSegment(std::stoi(ui->lineEdit_rmTime_h->text().toStdString()),
                                             std::stoi(ui->lineEdit_rmTime_m->text().toStdString())));

        if (ui->lineEdit_taskLoc->isModified())
            task->set_taskLoc(ui->lineEdit_taskLoc->text());

        if (ui->comboBox_taskPrio->isWindowModified())
            task->set_taskPrio(toTaskPriority(ui->comboBox_taskPrio->currentText()));

        if (ui->comboBox_taskCtg->isWindowModified())
            task->set_taskCtg(Task::toCtgIndex(ui->comboBox_taskCtg->currentText().toStdString()));

        if (ui->textEdit_taskNote->isWindowModified())
            task->set_taskNote(ui->textEdit_taskNote->toPlainText());

        mainPage->show();
        this->close();
    });
}

task_info_window::~task_info_window()
{
    delete ui;
}
