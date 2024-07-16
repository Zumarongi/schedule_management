#include "create_task_window.h"
#include "ui_create_task_window.h"
#include "account.h"
#include "time_conflict_dialog.h"
#include "mainwindow.h"

extern Account *currentAccount;
extern MainWindow *mainPage;

create_task_window::create_task_window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::create_task_window)
{
    ui->setupUi(this);

    // ui->dateTimeEdit_stTime->setMinimumDateTime(QDateTime::currentDateTime());
    // ui->dateTimeEdit_edTime->setMinimumDateTime(QDateTime::currentDateTime());
    ui->lineEdit_rmTime_h->setValidator(new QIntValidator(0, 23, this));
    ui->lineEdit_rmTime_m->setValidator(new QIntValidator(0, 59, this));
    ui->comboBox_taskPrio->setEditable(false);
    ui->comboBox_taskCtg->setEditable(false);

    ui->lineEdit_taskName->setText("");
    ui->dateTimeEdit_stTime->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_edTime->setDateTime(QDateTime::currentDateTime().addDuration(std::chrono::milliseconds(3600000)));
    ui->lineEdit_rmTime_h->setText("0");
    ui->lineEdit_rmTime_m->setText("0");
    ui->lineEdit_taskLoc->setText("");
    ui->comboBox_taskPrio->setCurrentText("低");
    ui->comboBox_taskCtg->setCurrentText("其他");
    ui->textEdit_taskNote->setText("");

    ui->warning_taskNameEmpty->hide();
    ui->warning_edTimeTooEarly->hide();
    ui->warning_rmTimeTooEarly->hide();

    ui->lineEdit_taskName->setReadOnly(false);
    ui->dateTimeEdit_stTime->setReadOnly(false);
    ui->dateTimeEdit_edTime->setReadOnly(false);
    ui->lineEdit_rmTime_h->setReadOnly(false);
    ui->lineEdit_rmTime_m->setReadOnly(false);
    ui->lineEdit_taskLoc->setReadOnly(false);
    ui->comboBox_taskPrio->setEnabled(true);
    ui->comboBox_taskCtg->setEnabled(true);
    ui->textEdit_taskNote->setReadOnly(false);

    connect(ui->pushButton_createTask, &QPushButton::clicked, [=](){
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
        bool rmTimeTooEarly = new_stTime - QDateTime::currentDateTime() < (std::chrono::milliseconds)(new_rmTime.msecsSinceStartOfDay());

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
            bool timeConflicted = false;
            for (auto task: currentAccount->get_taskList())
                if ((new_stTime <= task->get_stTime() && task->get_stTime() <= new_edTime) || (new_stTime <= task->get_edTime() && task->get_edTime() <= new_edTime))
                {
                    timeConflicted = true;
                    break;
                }
            bool forceToSave = false;
            if (timeConflicted)
            {
                time_conflict_dialog *timeConfDialog = new time_conflict_dialog(this);
                timeConfDialog->show();
                connect(timeConfDialog, &time_conflict_dialog::forcedSave, [&](){forceToSave = true;});
                timeConfDialog->exec();
            }
            if (!timeConflicted || forceToSave)
            {
                qDebug() << "ready to create task";
                Task *new_task = new Task(new_taskName, new_stTime, new_edTime, new_rmTime, new_taskLoc, new_taskPrio, new_taskCtg, new_taskNote);
                currentAccount->addTask(new_task);

                emit done_creation();

                mainPage->show();
                this->close();
            }
        }
    });

    connect(ui->pushButton_cancel, &QPushButton::clicked, [=](){
        mainPage->show();
        this->close();
    });
}

create_task_window::~create_task_window()
{
    delete ui;
}
