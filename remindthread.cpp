#include "remindthread.h"
#include <QDebug>

QMutex remindThread::mutex;

remindThread::remindThread(QObject *parent)
    : QObject{parent}
{}

remindThread::~remindThread(){
    timer->stop();
    timer->deleteLater();
}

void remindThread::onCreateTimer(){
    // 等待至整分钟
    timer = new QTimer();
    timer->setInterval(1000);
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
        if(task->get_stTime()<QDateTime::currentDateTime() && task->get_edTime()>QDateTime::currentDateTime()
            && !task->get_isReminded()){
            emit inProgress(task);
        }
    }
    mutex.unlock();
}
