#include "create_task_window.h"
#include "ui_create_task_window.h"
#include "account.h"
#include "mainwindow.h"

extern Account *currentAccount;
extern MainWindow *mainPage;

#define _FONT(s) QFont("Times New Roman", (s))
#define FONT _FONT(10)

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
    qDebug() << "init_stTime =" << init_stTime;
    qDebug() << "init_edTime =" << init_edTime;
}

void create_task_window::setupInitValues()
{
    ui->lineEdit_rmTime_h->setValidator(new QIntValidator(0, 23, this));
    ui->lineEdit_rmTime_m->setValidator(new QIntValidator(0, 59, this));
    ui->comboBox_taskPrio->setEditable(false);
    ui->comboBox_taskCtg->setEditable(false);

    ui->lineEdit_taskName->setText("");
    getInitTime();
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
    // this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowTitle("任务创建");

    QVBoxLayout *pageLayout = new QVBoxLayout;
    {
        QGridLayout *taskInfoLayout = new QGridLayout;
        {
            // 第一列（均为label）
            ui->label_taskName->setFixedSize(55, 20);
            ui->label_taskName->setAlignment(Qt::AlignBottom);
            ui->label_taskName->setFont(FONT);
            taskInfoLayout->addWidget(ui->label_taskName, 0, 0, Qt::AlignLeft);
            ui->label_stTime->setFixedSize(55, 20);
            ui->label_stTime->setAlignment(Qt::AlignBottom);
            ui->label_stTime->setFont(FONT);
            taskInfoLayout->addWidget(ui->label_stTime, 1, 0, Qt::AlignLeft);
            ui->label_taskLoc->setFixedSize(55, 20);
            ui->label_taskLoc->setAlignment(Qt::AlignBottom);
            ui->label_taskLoc->setFont(FONT);
            taskInfoLayout->addWidget(ui->label_taskLoc, 2, 0, Qt::AlignLeft);
            ui->label_rmTime->setFixedSize(55, 20);
            ui->label_rmTime->setAlignment(Qt::AlignBottom);
            ui->label_rmTime->setFont(FONT);
            taskInfoLayout->addWidget(ui->label_rmTime, 3, 0, Qt::AlignLeft);
            ui->label_taskNote->setFixedSize(55, 20);
            ui->label_taskNote->setAlignment(Qt::AlignBottom);
            ui->label_taskNote->setFont(FONT);
            taskInfoLayout->addWidget(ui->label_taskNote, 4, 0, Qt::AlignLeft);

            // 第二列
            ui->lineEdit_taskName->setFixedSize(120, 30);
            ui->lineEdit_taskName->setFont(FONT);
            taskInfoLayout->addWidget(ui->lineEdit_taskName, 0, 1, Qt::AlignLeft);
            ui->dateTimeEdit_stTime->setFixedSize(200, 30);
            ui->dateTimeEdit_stTime->setFont(FONT);
            taskInfoLayout->addWidget(ui->dateTimeEdit_stTime, 1, 1, Qt::AlignLeft);
            ui->lineEdit_taskLoc->setFixedSize(120, 30);
            ui->lineEdit_taskLoc->setFont(FONT);
            taskInfoLayout->addWidget(ui->lineEdit_taskLoc, 2, 1, Qt::AlignLeft);
            QHBoxLayout *rmTimeLayout = new QHBoxLayout;
            {
                ui->lineEdit_rmTime_h->setFixedSize(50, 30);
                ui->lineEdit_rmTime_h->setFont(FONT);
                rmTimeLayout->addWidget(ui->lineEdit_rmTime_h);
                ui->label_rmTime_h->setFixedSize(30, 30);
                ui->label_rmTime_h->setAlignment(Qt::AlignBottom);
                ui->label_rmTime_h->setFont(FONT);
                rmTimeLayout->addWidget(ui->label_rmTime_h);
                ui->lineEdit_rmTime_m->setFixedSize(50, 30);
                ui->lineEdit_rmTime_m->setFont(FONT);
                rmTimeLayout->addWidget(ui->lineEdit_rmTime_m);
                ui->label_rmTime_m->setFixedSize(45, 30);
                ui->label_rmTime_m->setAlignment(Qt::AlignBottom);
                ui->label_rmTime_m->setFont(FONT);
                rmTimeLayout->addWidget(ui->label_rmTime_m);
            }taskInfoLayout->addLayout(rmTimeLayout, 3, 1, Qt::AlignLeft);
            ui->textEdit_taskNote->setFixedSize(200, 60);
            ui->textEdit_taskNote->setFont(FONT);
            taskInfoLayout->addWidget(ui->textEdit_taskNote, 4, 1, Qt::AlignLeft);

            // 第三列（均为label）
            ui->label_taskPrio->setFixedSize(55, 20);
            ui->label_taskPrio->setAlignment(Qt::AlignBottom);
            ui->label_taskPrio->setFont(FONT);
            taskInfoLayout->addWidget(ui->label_taskPrio, 0, 2, Qt::AlignLeft);
            ui->label_edTime->setFixedSize(55, 20);
            ui->label_edTime->setAlignment(Qt::AlignBottom);
            ui->label_edTime->setFont(FONT);
            taskInfoLayout->addWidget(ui->label_edTime, 1, 2, Qt::AlignLeft);
            ui->label_taskCtg->setFixedSize(55, 20);
            ui->label_taskCtg->setAlignment(Qt::AlignBottom);
            ui->label_taskCtg->setFont(FONT);
            taskInfoLayout->addWidget(ui->label_taskCtg, 2, 2, Qt::AlignLeft);

            // 第四列
            ui->comboBox_taskPrio->setFixedSize(60, 30);
            ui->comboBox_taskPrio->setFont(FONT);
            taskInfoLayout->addWidget(ui->comboBox_taskPrio, 0, 3, Qt::AlignLeft);
            ui->dateTimeEdit_edTime->setFixedSize(200, 30);
            ui->dateTimeEdit_edTime->setFont(FONT);
            taskInfoLayout->addWidget(ui->dateTimeEdit_edTime, 1, 3, Qt::AlignLeft);
            ui->comboBox_taskCtg->setFixedSize(60, 30);
            ui->comboBox_taskCtg->setFont(FONT);
            taskInfoLayout->addWidget(ui->comboBox_taskCtg, 2, 3, Qt::AlignLeft);
        }pageLayout->addLayout(taskInfoLayout);

        QHBoxLayout *buttonLayout = new QHBoxLayout;
        {
            ui->pushButton_createTask->setFixedSize(80, 30);
            ui->pushButton_createTask->setFont(FONT);
            ui->pushButton_createTask->setStyleSheet("QPushButton{border-radius:8px;background-color:#148AFF;color:#FFFFFF;}");
            buttonLayout->addWidget(ui->pushButton_createTask);
            ui->pushButton_cancel->setFixedSize(80, 30);
            ui->pushButton_cancel->setFont(FONT);
            ui->pushButton_cancel->setStyleSheet("QPushButton{border-radius:8px;background-color:#148AFF;color:#FFFFFF;}");
            buttonLayout->addWidget(ui->pushButton_cancel);
        }pageLayout->addLayout(buttonLayout);

        pageLayout->setContentsMargins(20, 10, 20, 10);
        pageLayout->setSpacing(15);
    }this->setLayout(pageLayout);
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
                QString taskowner = currentAccount->get_userName();
                Task *new_task = new Task(taskowner, new_taskName, new_stTime, new_edTime, new_rmTime, new_taskLoc, new_taskPrio, new_taskCtg, new_taskNote);
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
