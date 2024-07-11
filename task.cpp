#include "task.h"
#include<fstream>
#include<iostream>

std::map<int, std::string> Task::mapCtg = {{0, "学习"}, {1, "娱乐"}, {2, "生活"}, {3, "工作"}, {4, "运动"}};

int Task::IdCounter = 0;

Task::Task(QString taskname, time_t st_time, time_t ed_time = -1, time_t rm_time = 30,
           QString taskloc = "", taskPriority taskprio = LOW, int taskctg = 0,
           QString tasknote = "")
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


