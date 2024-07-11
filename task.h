#ifndef TASK_H
#define TASK_H

#include<string>
#include<map>
#include <QMessageBox>

enum taskPriority { LOW = 0, MID, HIGH };

class Task
{
    static std::map<int, std::string> mapCtg;

    static int IdCounter;
    int taskId;

    QString taskName;
    time_t stTime, edTime, rmTime;  // start, end, reminder
    QString taskLoc;            // location
    taskPriority taskPrio;
    int taskCtg;                    //catagory
    QString taskNote;

public:
    Task(QString taskname, time_t st_time, time_t ed_time, time_t rm_time,
         QString taskloc, taskPriority taskprio, int taskctg,
         QString tasknote);
    bool saveToFile();
    void printInfo();

};

#endif // TASK_H
