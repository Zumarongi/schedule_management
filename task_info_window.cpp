#include "task_info_window.h"
#include "ui_task_info_window.h"
#include "mainwindow.h"
#include "delete_confirm_dialog.h"

extern MainWindow *mainPage;
extern Account *currentAccount;

task_info_window::task_info_window(Task *task, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::task_info_window)
{
    ui->setupUi(this);

    currentTask = task;

    ui->dateTimeEdit_stTime->setMinimumDateTime(QDateTime::currentDateTime());
    ui->lineEdit_rmTime_h->setValidator(new QIntValidator(0, 23, this));
    ui->lineEdit_rmTime_m->setValidator(new QIntValidator(0, 59, this));
    ui->comboBox_taskPrio->setEditable(false);
    ui->comboBox_taskCtg->setEditable(false);

    ui->lineEdit_taskName->setText(task->get_taskName());
    ui->dateTimeEdit_stTime->setDateTime(task->get_stTime());
    ui->dateTimeEdit_edTime->setDateTime(task->get_edTime());
    ui->lineEdit_rmTime_h->setText(QString::fromStdString(std::to_string(task->get_rmTime().hour())));
    ui->lineEdit_rmTime_m->setText(QString::fromStdString(std::to_string(task->get_rmTime().minute())));
    ui->lineEdit_taskLoc->setText(task->get_taskLoc());
    ui->comboBox_taskPrio->setCurrentText(toQString(task->get_taskPrio()));
    ui->comboBox_taskCtg->setCurrentText(Task::toCtgQString(task->get_taskCtg()));
    ui->textEdit_taskNote->setText(task->get_taskNote());

    ui->warning_taskNameEmpty->hide();
    ui->warning_stTimeTooEarly->hide();
    ui->warning_edTimeTooEarly->hide();
    ui->warning_rmTimeTooEarly->hide();

    ui->lineEdit_taskName->setReadOnly(true);
    connect(ui->editButton_taskName, &QPushButton::clicked, [=](){
        ui->lineEdit_taskName->setReadOnly(false);
    });

    ui->dateTimeEdit_stTime->setReadOnly(true);
    connect(ui->editButton_stTime, &QPushButton::clicked, [=](){
        ui->dateTimeEdit_stTime->setReadOnly(false);
    });

    ui->dateTimeEdit_edTime->setReadOnly(true);
    connect(ui->editButton_edTime, &QPushButton::clicked, [=](){
        ui->dateTimeEdit_edTime->setReadOnly(false);
    });

    ui->lineEdit_rmTime_h->setReadOnly(true);
    ui->lineEdit_rmTime_m->setReadOnly(true);
    connect(ui->editButton_rmTime, &QPushButton::clicked, [=](){
        ui->lineEdit_rmTime_h->setReadOnly(false);
        ui->lineEdit_rmTime_m->setReadOnly(false);
    });

    ui->lineEdit_taskLoc->setReadOnly(true);
    connect(ui->editButton_taskLoc, &QPushButton::clicked, [=](){
        ui->lineEdit_taskLoc->setReadOnly(false);
    });

    ui->comboBox_taskPrio->setEnabled(false);
    connect(ui->editButton_taskPrio, &QPushButton::clicked, [=](){
        ui->comboBox_taskPrio->setEnabled(true);
    });

    ui->comboBox_taskCtg->setEnabled(false);
    connect(ui->editButton_taskCtg, &QPushButton::clicked, [=](){
        ui->comboBox_taskCtg->setEnabled(true);
    });

    ui->textEdit_taskNote->setReadOnly(true);
    connect(ui->editButton_taskNote, &QPushButton::clicked, [=](){
        ui->textEdit_taskNote->setReadOnly(false);
    });

    connect(ui->pushButton_saveChanges, &QPushButton::clicked, [=](){
        QString new_taskName = ui->lineEdit_taskName->text();
        QDateTime new_stTime = ui->dateTimeEdit_stTime->dateTime();
        QDateTime new_edTime = ui->dateTimeEdit_edTime->dateTime();
        QTime new_rmTime = QTime(std::stoi(ui->lineEdit_rmTime_h->text().toStdString()), std::stoi(ui->lineEdit_rmTime_m->text().toStdString()));
        QString new_taskLoc = ui->lineEdit_taskLoc->text();
        TaskPriority new_taskPrio = toTaskPriority(ui->comboBox_taskPrio->currentText());
        int new_taskCtg = Task::toCtgIndex(ui->comboBox_taskCtg->currentText().toStdString());
        QString new_taskNote = ui->textEdit_taskNote->toPlainText();

        bool taskNameEmpty = new_taskName.isEmpty();
        bool edTimeTooEarly = new_edTime < new_stTime;
        bool rmTimeTooEarly = new_stTime - QDateTime::currentDateTime() < (std::chrono::milliseconds)(new_rmTime.msec());

        if (taskNameEmpty)
            ui->warning_taskNameEmpty->show();
        else ui->warning_taskNameEmpty->hide();

        if (edTimeTooEarly)
            ui->warning_edTimeTooEarly->show();
        else ui->warning_edTimeTooEarly->hide();

        if (rmTimeTooEarly)
            ui->warning_rmTimeTooEarly->show();
        else ui->warning_rmTimeTooEarly->hide();

        if (!taskNameEmpty && !edTimeTooEarly && !rmTimeTooEarly)
        {
            task->set_taskName(new_taskName);
            task->set_stTime(new_stTime);
            task->set_edTime(new_edTime);
            task->set_rmTime(new_rmTime);
            task->set_taskLoc(new_taskLoc);
            task->set_taskPrio(new_taskPrio);
            task->set_taskCtg(new_taskCtg);
            task->set_taskNote(new_taskNote);

            std::filesystem::path task_path = ROOTDIR + "/data/" + currentAccount->get_userName().toStdString() + "/" + std::to_string(task->get_taskId()) + ".task";
            task->saveToFile(task_path);

            mainPage->show();
            this->close();
        }
    });

    connect(ui->pushButton_deleteTask, &QPushButton::clicked, [=](){
        delete_confirm_dialog *delConfDialog = new delete_confirm_dialog(this);
        delConfDialog->show();
    });

    connect(ui->pushButton_return, &QPushButton::clicked, [=](){
        mainPage->show();
        this->close();
    });
}

task_info_window::~task_info_window()
{
    delete ui;
}

Task *task_info_window::get_currentTask() const
{
    return currentTask;
}
