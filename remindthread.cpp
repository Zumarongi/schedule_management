#include "remindthread.h"
#include <QDebug>

QMutex remindThread::mutex;

remindThread::remindThread(QObject *parent)
    : QThread{parent}
{}

void remindThread::run(){
    timer= new QTimer (this);
    timer->start(1000);
    connect(timer,&QTimer::timeout,[=](){
        qDebug()<<"timeout";
        mutex.lock();
        auto taskList = currentAccount->get_taskList();
        mutex.unlock();
        for (auto task: taskList)
            if (task->get_stTime() - QDateTime::currentDateTime() < (std::chrono::milliseconds)task->get_rmTime().msecsSinceStartOfDay()){
                remindPage = new remindDialog(task);
                remindPage->exec();
                delete remindPage;
            }
    });
}
