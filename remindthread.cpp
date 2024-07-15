#include "remindthread.h"

QMutex remindThread::mutex;

remindThread::remindThread(QObject *parent)
    : QThread{parent}
{}

void remindThread::run(){
    QTimer *timer= new QTimer ();
    timer->setInterval(1000);
    connect(timer,&QTimer::timeout,[=](){
        mutex.lock();
        for (auto task: currentAccount->get_taskList())
            if (task->get_stTime() - QDateTime::currentDateTime() < (std::chrono::milliseconds)task->get_rmTime().msecsSinceStartOfDay())
                remindDialog *remindPage = new remindDialog(task);
        mutex.unlock();
    });
}
