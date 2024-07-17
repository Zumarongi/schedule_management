#include "remindthread.h"
#include <QDebug>

QMutex remindThread::mutex;

remindThread::remindThread(QObject *parent)
    : QObject{parent}
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

  remindThread::~remindThread(){
    timer->stop();
    timer->deleteLater();
}

void remindThread::onCreateTimer(){
    timer = new QTimer();
    timer->setInterval(60000);
    connect(timer, &QTimer::timeout, this, &remindThread::onTimeout);
    timer->start();
}

void remindThread::onTimeout(){
    qDebug()<<"timeout";
    mutex.lock();
    for (auto task: currentAccount->get_taskList()){
        if ((task->get_stTime() - QDateTime::currentDateTime() < (std::chrono::milliseconds)task->get_rmTime().msecsSinceStartOfDay())
            && (task->get_stTime() > QDateTime::currentDateTime()) && !task->get_isReminded()){
            emit showRemind(task);
        }
        if(currentAccount->get_doneAndDel() && task->get_edTime()<QDateTime::currentDateTime()){
            currentAccount->delTask(task);
            emit reorder();
        }
    }
    mutex.unlock();
}
