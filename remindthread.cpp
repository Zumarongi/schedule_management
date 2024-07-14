#include "remindthread.h"

remindThread::remindThread(QObject *parent)
    : QThread{parent}
{}

void remindThread::run(){
    QTimer *timer= new QTimer ();
    timer->setInterval(1000);
    connect(timer,&QTimer::timeout,[=](){
        currentTime=time(NULL);
        for(int i=0;i<currentAccount->taskList.size();++i){
            if((currentAccount->taskList[i]->get_stTime()-currentTime)<currentAccount->taskList[i]->get_rmTime()){
                arrive_remind_time *remindPage=new arrive_remind_time(currentAccount->taskList[i]);;

            }
        }
    });
}
