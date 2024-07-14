#include "remindthread.h"

remindThread::remindThread(QObject *parent)
    : QThread{parent}
{}

void remindThread::run(){
    QTimer *timer= new QTimer ();
    timer->setInterval(1000);
    connect(timer,&QTimer::timeout,[=](){
        for (auto task: currentAccount->get_taskList())
        {
            if (task)
        }
        for(int i=0;i<currentAccount->taskList.size();++i){
            if((currentAccount->taskList[i]->get_stTime()-QDateTime::currentDateTime())<
                (std::chrono::milliseconds)currentAccount->taskList[i]->get_rmTime().msec()){
                remindDialog *remindPage=new remindDialog(currentAccount->taskList[i]);;

            }
        }
    });
}
