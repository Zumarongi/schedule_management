#ifndef REMINDDIALOG_H
#define REMINDDIALOG_H

#include <QDialog>
#include "task.h"
#include <QDateTime>
#include "task_info_window.h"
#include <QString>

namespace Ui {
class remindDialog;
}

class remindDialog : public QDialog
{
    Q_OBJECT
    Task *currenTask;
    QTime new_rmTime=QTime();

public:
    explicit remindDialog(Task *getTask,QWidget *parent = nullptr);
    ~remindDialog();

private slots:
    void on_task_info_button_clicked();

private:
    Ui::remindDialog *ui;
    void setLayout();
};

#endif // REMINDDIALOG_H
