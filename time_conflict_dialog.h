#ifndef TIME_CONFLICT_DIALOG_H
#define TIME_CONFLICT_DIALOG_H

#include <QDialog>

namespace Ui {
class time_conflict_dialog;
}

class time_conflict_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit time_conflict_dialog(QWidget *parent = nullptr);
    ~time_conflict_dialog();

private:
    Ui::time_conflict_dialog *ui;
};

#endif // TIME_CONFLICT_DIALOG_H
