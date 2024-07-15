#ifndef TIME_CONFLICT_DIALOG_H
#define TIME_CONFLICT_DIALOG_H

#include "create_task_window.h"
#include "task_info_window.h"

#include <QDialog>

namespace Ui {
class time_conflict_dialog;
}

class time_conflict_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit time_conflict_dialog(create_task_window *parent = nullptr);
    explicit time_conflict_dialog(task_info_window *parent = nullptr);
    ~time_conflict_dialog();

signals:
    void forcedSave();

private:
    Ui::time_conflict_dialog *ui;
};

#endif // TIME_CONFLICT_DIALOG_H
