#ifndef REMINDTHREAD_H
#define REMINDTHREAD_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include "account.h"
#include "arrive_remind_time.h"

extern Account *currentAccount;

class remindThread : public QThread
{
    Q_OBJECT
    time_t currentTime;

public:
    explicit remindThread(QObject *parent = nullptr);

protected:
    void run() override;

};

#endif // REMINDTHREAD_H
