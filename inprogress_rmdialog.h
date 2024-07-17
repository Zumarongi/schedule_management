#ifndef INPROGRESS_RMDIALOG_H
#define INPROGRESS_RMDIALOG_H

#include <QDialog>
#include "task.h"
#include "account.h"

namespace Ui {
class inProgress_rmDialog;
}

class inProgress_rmDialog : public QDialog
{
    Q_OBJECT
    Task * currenTask;

public:
    explicit inProgress_rmDialog(Task *task,QWidget *parent = nullptr);
    ~inProgress_rmDialog();

private slots:
    void on_OK_pushButton_clicked();

private:
    Ui::inProgress_rmDialog *ui;
};

#endif // INPROGRESS_RMDIALOG_H
