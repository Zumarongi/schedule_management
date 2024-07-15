#ifndef DELETE_CONFIRM_DIALOG_H
#define DELETE_CONFIRM_DIALOG_H

#include "task_info_window.h"
#include <QDialog>
#include "task.h"

namespace Ui {
class delete_confirm_dialog;
}

class delete_confirm_dialog : public QDialog
{
    Q_OBJECT
    Task * currenTask;

public:
    explicit delete_confirm_dialog(Task *task,task_info_window *parent = nullptr);
    ~delete_confirm_dialog();

signals:
    void doneDel();

private:
    Ui::delete_confirm_dialog *ui;
};

#endif // DELETE_CONFIRM_DIALOG_H
