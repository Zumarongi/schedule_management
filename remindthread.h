#ifndef REMINDTHREAD_H
#define REMINDTHREAD_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include "account.h"
#include "reminddialog.h"

extern Account *currentAccount;

class remindThread : public QThread
{
    Q_OBJECT

public:
    explicit remindThread(QObject *parent = nullptr);

protected:
    void run() override;

};

#endif // REMINDTHREAD_H
