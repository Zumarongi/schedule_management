#include "account.h"
#include<fstream>
#include<iostream>

int Task::IdCounter = 0;

Task::Task(std::string taskname, time_t st_time, time_t ed_time = -1, time_t rm_time = 30,
           std::string taskloc = "", taskPriority taskprio = LOW, int taskctg = 0,
           std::string tasknote = "")
{
    taskId = ++ IdCounter;
    
    taskName = taskname;
    
    stTime = st_time;
    if (ed_time == -1) edTime = st_time + 30;
    rmTime = rm_time;
    
    taskLoc = taskloc;
    
    taskPrio = taskprio;
    
    taskCtg = taskctg;

    taskNote = tasknote;
}

bool Task::saveToFile()
{
    std::ofstream fout(".task//" + taskName + ".task");
    if (!fout.is_open())
    {
        std::cerr << "Not able to create .task file" << std::endl;
        return false;
    }
    fout << taskName << std::endl;
    fout << stTime << std::endl;
    fout << edTime << std::endl;
    fout << rmTime << std::endl;
    fout << taskLoc << std::endl;
    fout << taskPrio << std::endl;
    fout << taskCtg << std::endl;
    fout << taskNote << std::endl;
    return true;
}

void printTimePoint(time_t time_point)
{
    /*
    PRINT
    */
}

void printTimeSegment(time_t st_time, time_t ed_time)
{
    printTimePoint(st_time);
    std::cout << " - " << std::endl;
    printTimePoint(ed_time);
}

std::string toTimeString_H(time_t rm_time)
{
    /*
    transfer rm_time to hours
    */
}

std::string toTimeString_M(time_t rm_time)
{
    /*
    transfer rm_time to minutes
    */
}

void Task::printInfo()
{
    std::cout << "Task: " + taskName << std::endl;
    printTimeSegment(stTime, edTime);
    std::cout << "Reminder Time: " + toTimeString_M(rmTime) + " before" << std::endl;
}