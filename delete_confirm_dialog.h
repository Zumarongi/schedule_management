#ifndef DELETE_CONFIRM_DIALOG_H
#define DELETE_CONFIRM_DIALOG_H

#include "task_info_window.h"
#include <QDialog>

namespace Ui {
class delete_confirm_dialog;
}

class delete_confirm_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit delete_confirm_dialog(task_info_window *parent = nullptr);
    ~delete_confirm_dialog();

private:
    Ui::delete_confirm_dialog *ui;
};

#endif // DELETE_CONFIRM_DIALOG_H
