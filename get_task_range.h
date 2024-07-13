#ifndef GET_TASK_RANGE_H
#define GET_TASK_RANGE_H

#include <QMainWindow>
#include "account.h"
#include "timeformat.h"

extern Account *currentAccount;


namespace Ui {
class get_task_range;
}

class get_task_range : public QMainWindow
{
    Q_OBJECT

public:
    explicit get_task_range(QWidget *parent = nullptr);
    ~get_task_range();

private:
    Ui::get_task_range *ui;
};

#endif // GET_TASK_RANGE_H
