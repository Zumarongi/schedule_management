#ifndef TASK_H
#define TASK_H

#include<string>
#include<map>

enum taskPriority { LOW = 0, MID, HIGH };

class Task
{
    static std::map<int, std::string> mapCtg;

    static int IdCounter;
    int taskId;

    std::string taskName;
    time_t stTime, edTime, rmTime;  // start, end, reminder
    std::string taskLoc;            // location
    taskPriority taskPrio;
    int taskCtg;                    //catagory
    std::string taskNote;

public:
    Task(std::string taskname, time_t st_time, time_t ed_time, time_t rm_time,
         std::string taskloc, taskPriority taskprio, int taskctg,
         std::string tasknote);
    bool saveToFile();
    void printInfo();

};

#endif // TASK_H
