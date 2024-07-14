#ifndef REMINDDIALOG_H
#define REMINDDIALOG_H

#include <QDialog>
#include "task.h"
#include <QDateTime>

namespace Ui {
class remindDialog;
}

class remindDialog : public QDialog
{
    Q_OBJECT
    Task *currenTask;

public:
    explicit remindDialog(Task *getTask,QWidget *parent = nullptr);
    ~remindDialog();

private:
    Ui::remindDialog *ui;
};

#endif // REMINDDIALOG_H
