#include "task_info_window.h"
#include "ui_task_info_window.h"
#include "mainwindow.h"

extern MainWindow *mainPage;
extern Account *currentAccount;
extern task_info_window *taskInfoPage;

#define _FONT(s) QFont("Times New Roman", (s))
#define FONT _FONT(10)

void task_info_window::setupInitValues()
{
    ui->lineEdit_rmTime_h->setValidator(new QIntValidator(0, 23, this));
    ui->lineEdit_rmTime_m->setValidator(new QIntValidator(0, 59, this));
    ui->comboBox_taskPrio->setEditable(false);
    ui->comboBox_taskCtg->setEditable(false);

    ui->lineEdit_taskName->setText(currentTask->get_taskName());
    ui->dateTimeEdit_stTime->setDateTime(currentTask->get_stTime());
    ui->dateTimeEdit_edTime->setDateTime(currentTask->get_edTime());
    ui->lineEdit_rmTime_h->setText(QString::fromStdString(std::to_string(currentTask->get_rmTime().hour())));
    ui->lineEdit_rmTime_m->setText(QString::fromStdString(std::to_string(currentTask->get_rmTime().minute())));
    ui->lineEdit_taskLoc->setText(currentTask->get_taskLoc());
    ui->comboBox_taskPrio->setCurrentText(toQString(currentTask->get_taskPrio()));
    ui->comboBox_taskCtg->setCurrentText(Task::toCtgQString(currentTask->get_taskCtg()));
    ui->textEdit_taskNote->setText(currentTask->get_taskNote());

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

void task_info_window::setupPageLayout()
{
    // this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowTitle("任务信息");

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
            ui->pushButton_saveChanges->setFixedSize(80, 30);
            ui->pushButton_saveChanges->setFont(FONT);
            buttonLayout->addWidget(ui->pushButton_saveChanges);
            ui->pushButton_deleteTask->setFixedSize(80, 30);
            ui->pushButton_deleteTask->setFont(FONT);
            buttonLayout->addWidget(ui->pushButton_deleteTask);
            ui->pushButton_return->setFixedSize(80, 30);
            ui->pushButton_return->setFont(FONT);
            buttonLayout->addWidget(ui->pushButton_return);
        }pageLayout->addLayout(buttonLayout);

        pageLayout->setContentsMargins(20, 10, 20, 10);
        pageLayout->setSpacing(15);
    }this->setLayout(pageLayout);
}

void showWarning(QString text)
{
    QMessageBox *warning = new QMessageBox;
    warning->setAttribute(Qt::WA_DeleteOnClose);
    warning->setIcon(QMessageBox::Icon::Warning);
    warning->setWindowTitle("警告");
    warning->setText(text);
    warning->addButton("确定", QMessageBox::AcceptRole);

    QObject::connect(warning, &QMessageBox::accepted, [=](){
        warning->close();
    });

    warning->exec();
}

void showCaution(QString text, QString buttonOkText, QString buttonCancelText, bool &accepted)
{
    QMessageBox *caution = new QMessageBox;
    caution->setAttribute(Qt::WA_DeleteOnClose);
    caution->setIcon(QMessageBox::Icon::Question);
    caution->setWindowTitle("提示");
    caution->setText(text);
    caution->addButton(buttonOkText, QMessageBox::AcceptRole);
    caution->addButton(buttonCancelText, QMessageBox::RejectRole);

    QObject::connect(caution, &QMessageBox::accepted, [=, &accepted](){
        accepted = true;
        caution->close();
    });
    QObject::connect(caution, &QMessageBox::rejected, [=, &accepted](){
        accepted = false;
        caution->close();
    });

    caution->exec();
}

task_info_window::task_info_window(Task *task, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::task_info_window)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    currentTask = task;

    setupInitValues();
    setupPageLayout();

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
        bool taskNameRepeated = false;
        for (auto task: currentAccount->get_taskList())
            if (task->get_taskId() != currentTask->get_taskId() && task->get_taskName() == new_taskName)
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
                if (task->get_taskId() != currentTask->get_taskId())
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
                currentTask->set_taskName(new_taskName);
                currentTask->set_stTime(new_stTime);
                currentTask->set_edTime(new_edTime);
                currentTask->set_rmTime(new_rmTime);
                currentTask->set_taskLoc(new_taskLoc);
                currentTask->set_taskPrio(new_taskPrio);
                currentTask->set_taskCtg(new_taskCtg);
                currentTask->set_taskNote(new_taskNote);

                currentAccount->saveToFile();
                std::filesystem::path task_path = ROOTDIR + "/data/" + currentAccount->get_userName().toStdString() + "/" + std::to_string(currentTask->get_taskId()) + ".task";
                // qDebug() << "In task_info_window: calling Task::saveToFile(task_path), task_path =" << task_path.string();
                task->saveToFile(task_path);

                mainPage = new MainWindow;
                emit mainPage->reorder();
                mainPage->show();
                this->close();
            }
        }
    });

    connect(ui->pushButton_deleteTask, &QPushButton::clicked, [=](){
        bool deleteConfirmed = false;
        showCaution("确认删除任务？", "确认", "取消", deleteConfirmed);
        if (deleteConfirmed)
        {
            currentAccount->delTask(currentTask);
            mainPage = new MainWindow;
            emit mainPage->reorder();
            mainPage->show();
            this->close();
        }
    });

    connect(ui->pushButton_return, &QPushButton::clicked, [=](){
        QString new_taskName = ui->lineEdit_taskName->text();
        QDateTime new_stTime = ui->dateTimeEdit_stTime->dateTime();
        QDateTime new_edTime = ui->dateTimeEdit_edTime->dateTime();
        QTime new_rmTime = QTime(std::stoi(ui->lineEdit_rmTime_h->text().toStdString()), std::stoi(ui->lineEdit_rmTime_m->text().toStdString()));
        QString new_taskLoc = ui->lineEdit_taskLoc->text();
        TaskPriority new_taskPrio = toTaskPriority(ui->comboBox_taskPrio->currentText());
        int new_taskCtg = Task::toCtgIndex(ui->comboBox_taskCtg->currentText().toStdString());
        QString new_taskNote = ui->textEdit_taskNote->toPlainText();

        bool isModified = currentTask->get_taskName() != new_taskName ||
                          currentTask->get_stTime() != new_stTime ||
                          currentTask->get_edTime() != new_edTime ||
                          currentTask->get_rmTime() != new_rmTime ||
                          currentTask->get_taskLoc() != new_taskLoc ||
                          currentTask->get_taskPrio() != new_taskPrio ||
                          currentTask->get_taskCtg() != new_taskCtg ||
                          currentTask->get_taskNote() != new_taskNote;
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

task_info_window::~task_info_window()
{
    taskInfoPage = nullptr;
    delete ui;
}

Task *task_info_window::get_currentTask() const
{
    return currentTask;
}
