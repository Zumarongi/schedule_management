#ifndef GET_TIME_RANGE_H
#define GET_TIME_RANGE_H

#include <QDialog>
#include "account.h"
#include "timeformat.h"

extern Account *currentAccount;

namespace Ui {
class get_time_range;
}

class get_time_range : public QDialog
{
    Q_OBJECT

public:
    explicit get_time_range(QWidget *parent = nullptr);
    ~get_time_range();

signals:
    void done_change();

private:
    Ui::get_time_range *ui;
};

#endif // GET_TIME_RANGE_H
