#include "create_task_window.h"
#include "ui_create_task_window.h"
#include "account.h"
#include "time_conflict_dialog.h"
#include "mainwindow.h"

extern Account *currentAccount;
extern MainWindow *mainPage;

void create_task_window::getInitTime()
{
    init_stTime = QDateTime::currentDateTime();
    int nextWholeHour = init_stTime.time().hour() + 1;
    if (nextWholeHour == 24)
    {
        nextWholeHour = 0;
        init_stTime = init_stTime.addDays(1);
    }
    init_stTime.setTime(QTime(nextWholeHour, 0));
    init_edTime = init_stTime.addSecs(3600);
}

void create_task_window::setupInitValues()
{
    ui->lineEdit_rmTime_h->setValidator(new QIntValidator(0, 23, this));
    ui->lineEdit_rmTime_m->setValidator(new QIntValidator(0, 59, this));
    ui->comboBox_taskPrio->setEditable(false);
    ui->comboBox_taskCtg->setEditable(false);

    ui->lineEdit_taskName->setText("");
    ui->dateTimeEdit_stTime->setDateTime(init_stTime);
    ui->dateTimeEdit_edTime->setDateTime(init_edTime);
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
}

void create_task_window::setupPageLayout()
{

}

extern void showWarning(QString text);

extern void showCaution(QString text, QString buttonOkText, QString buttonCancelText, bool &accepted);

create_task_window::create_task_window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::create_task_window)
{
    ui->setupUi(this);

    setupInitValues();
    setupPageLayout();

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
        bool taskNameRepeated = false;
        for (auto task: currentAccount->get_taskList())
            if (task->get_taskName() == new_taskName)
            {
                taskNameRepeated = true;
                break;
            }
        bool edTimeTooEarly = new_edTime < new_stTime;
        bool rmTimeTooEarly = new_stTime - QDateTime::currentDateTime() < (std::chrono::milliseconds)(new_rmTime.msecsSinceStartOfDay());

        if (taskNameEmpty) showWarning("任务名称不能为空！");
        if (taskNameRepeated) showWarning("任务名称不能重复！");
        if (edTimeTooEarly) showWarning("结束时间不能早于开始时间！");
        if (rmTimeTooEarly) showWarning("提醒时间不能早于现在！");

        if (!taskNameEmpty && !taskNameRepeated && !edTimeTooEarly && !rmTimeTooEarly)
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
                showCaution("该任务时间与其他任务有冲突，\n确认保存？", "保存", "取消", forceToSave);
            if (!timeConflicted || forceToSave)
            {
                Task *new_task = new Task(new_taskName, new_stTime, new_edTime, new_rmTime, new_taskLoc, new_taskPrio, new_taskCtg, new_taskNote);
                currentAccount->addTask(new_task);

                mainPage=new MainWindow;
                emit mainPage->reorder();
                mainPage->show();
                this->close();
            }
        }
    });

    connect(ui->pushButton_cancel, &QPushButton::clicked, [=](){
        QString new_taskName = ui->lineEdit_taskName->text();
        QDateTime new_stTime = ui->dateTimeEdit_stTime->dateTime();
        QDateTime new_edTime = ui->dateTimeEdit_edTime->dateTime();
        QTime new_rmTime = QTime(std::stoi(ui->lineEdit_rmTime_h->text().toStdString()), std::stoi(ui->lineEdit_rmTime_m->text().toStdString()));
        QString new_taskLoc = ui->lineEdit_taskLoc->text();
        TaskPriority new_taskPrio = toTaskPriority(ui->comboBox_taskPrio->currentText());
        int new_taskCtg = Task::toCtgIndex(ui->comboBox_taskCtg->currentText().toStdString());
        QString new_taskNote = ui->textEdit_taskNote->toPlainText();

        bool isModified = new_taskName != "" ||
                          new_stTime != init_stTime ||
                          new_edTime != init_edTime ||
                          new_rmTime != QTime(0, 0) ||
                          new_taskLoc != "" ||
                          new_taskPrio != LOW ||
                          new_taskCtg != 6 ||
                          new_taskNote != "";
        bool returnConfirmed = false;
        if (isModified)
            showCaution("您有未保存的修改，\n确定返回？", "返回", "取消", returnConfirmed);
        if (!isModified || returnConfirmed)
        {
            mainPage = new MainWindow;
            emit mainPage->reorder();
            mainPage->show();
            this->close();
        }
    });
}

create_task_window::~create_task_window()
{
    delete ui;
}
