#ifndef REMINDTHREAD_H
#define REMINDTHREAD_H

#include <QMutex>
#include <QObject>
#include <QThread>
#include <QTimer>
#include "account.h"
#include "reminddialog.h"

extern Account *currentAccount;

class remindThread : public QObject
{
    Q_OBJECT
    QTimer *timer=NULL;
    remindDialog *remindPage;

    static QMutex mutex;

public:
    explicit remindThread(QObject *parent = nullptr);
    ~remindThread();

signals:
    void showRemind(Task *task);
    void reorder();

public slots:
    void onCreateTimer();
    void onTimeout();


};

#endif // REMINDTHREAD_H
