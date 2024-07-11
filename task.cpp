#include "task.h"
#include<fstream>
#include<iostream>

std::map<int, std::string> Task::mapCtg = {{0, "学习"}, {1, "娱乐"}, {2, "生活"}, {3, "工作"}, {4, "运动"}};

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

void Task::mod_taskName(std::string new_taskName) { taskName = new_taskName; }

void Task::mod_stTime(time_t new_stTime) { stTime = new_stTime; }

void Task::mod_edTime(time_t new_edTime) { edTime = new_edTime; }

void Task::mod_rmTime(time_t new_rmTime) { rmTime = new_rmTime; }

void Task::mod_taskLoc(std::string new_taskLoc) { taskLoc = new_taskLoc; }

void Task::mod_taskPrio(taskPriority new_taskPrio) { taskPrio = new_taskPrio; }

void Task::mod_taskCtg(int new_taskCtg) { taskCtg = new_taskCtg; }

void Task::mod_taskNote(std::string new_taskNote) { taskNote = new_taskNote; }
