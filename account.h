
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<string>
#include<vector>
#include<map>

    enum taskPriority { LOW = 0, MID, HIGH };

std::map<int, std::string> mpCtg;

class Task
{
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

    class account
{

public:
    std::string Username;
    std::string encryptedPass;
    std::vector<Task *> taskList;
    bool showHelp;
    bool doneAndDel;

    account();
};

#endif //_ACCOUNT_H_
#endif // ACCOUNT_H
