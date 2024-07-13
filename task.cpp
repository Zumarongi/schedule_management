#include "task.h"
#include <fstream>
#include <iostream>
#include <QDebug>

std::map<int, std::string> Task::ctgIdxToStr = {{0, "学习"}, {1, "娱乐"}, {2, "生活"}, {3, "工作"}, {4, "运动"}};
std::map<std::string, int> Task::ctgStrToIdx = {{"学习", 0}, {"娱乐", 1}, {"生活", 2}, {"工作", 3}, {"运动", 4}};

int Task::IdCounter = 0;

Task::Task(QString taskname, time_t st_time, time_t ed_time = -1, time_t rm_time = 30,
           QString taskloc = "", taskPriority taskprio = LOW, int taskctg = 0,
           QString tasknote = "")
{
    taskId = ++ IdCounter;
    taskName = taskname;
    stTime = st_time;
    if (ed_time == -1)
        edTime = st_time + 30;
    rmTime = rm_time;
    taskLoc = taskloc;
    taskPrio = taskprio;
    taskCtg = taskctg;
    taskNote = tasknote;
}

Task::Task(int taskid,
           QString taskname, time_t st_time, time_t ed_time, time_t rm_time,
           QString taskloc, taskPriority taskprio, int taskctg,
           QString tasknote)
{
    taskId = taskid;
    taskName = taskname;
    stTime = st_time;
    edTime = ed_time;
    rmTime = rm_time;
    taskLoc = taskloc;
    taskPrio = taskprio;
    taskCtg = taskctg;
    taskNote = tasknote;
}

bool Task::saveToFile(std::filesystem::path acc_path) const
{
    std::filesystem::path task_path = acc_path.append("/" + std::to_string(taskId) + ".task");
    std::ofstream fout(task_path);
    fout << taskId << std::endl;
    fout << taskName.toStdString() << std::endl;
    fout << stTime << std::endl;
    fout << edTime << std::endl;
    fout << taskLoc.toStdString() << std::endl;
    fout << taskPrio << std::endl;
    fout << taskCtg << std::endl;
    fout << taskNote.toStdString() << std::endl;
    fout.close();
    return true;
}

int Task::toCtgIndex(std::string ctgStr) { return ctgStrToIdx[ctgStr]; }

int Task::toCtgIndex(QString ctgqStr) { return ctgStrToIdx[ctgqStr.toStdString()]; }

std::string Task::toCtgString(int ctgIdx) { return ctgIdxToStr[ctgIdx]; }

int Task::getIdCounter() { return IdCounter; }

void Task::setIdCounter(int idcounter) { IdCounter = idcounter; }

bool (*Task::taskId_ascending)(const Task *, const Task *) = [](const Task *x, const Task *y) -> bool { return x->taskId < y->taskId; };

bool (*Task::taskId_descending)(const Task *, const Task *) = [](const Task *x, const Task *y) -> bool { return x->taskId > y->taskId; };

bool (*Task::taskName_ascending)(const Task *, const Task *) = [](const Task *x, const Task *y) -> bool { return x->taskName < y->taskName; };

bool (*Task::taskName_descending)(const Task *, const Task *) = [](const Task *x, const Task *y) -> bool { return x->taskName > y->taskName; };

bool (*Task::stTime_ascending)(const Task *, const Task *) = [](const Task *x, const Task *y) -> bool { return x->stTime < y->stTime; };

bool (*Task::stTime_descending)(const Task *, const Task *) = [](const Task *x, const Task *y) -> bool { return x->stTime > y->stTime; };

int Task::get_taskId() const { return taskId; }

QString Task::get_taskName() const { return taskName; }

time_t Task::get_stTime() const { return stTime; }

time_t Task::get_edTime() const { return edTime; }

time_t Task::get_rmTime() const { return rmTime; }

QString Task::get_taskLoc() const { return taskLoc; }

taskPriority Task::get_taskPrio() const { return taskPrio; }

int Task::get_taskCtg() const { return taskCtg; }

QString Task::get_taskNote() const { return taskNote; }

void Task::set_taskName(QString new_taskName) { taskName = new_taskName; }

void Task::set_stTime(time_t new_stTime) { stTime = new_stTime; }

void Task::set_edTime(time_t new_edTime) { edTime = new_edTime; }

void Task::set_rmTime(time_t new_rmTime) { rmTime = new_rmTime; }

void Task::set_taskLoc(QString new_taskLoc) { taskLoc = new_taskLoc; }

void Task::set_taskPrio(taskPriority new_taskPrio) { taskPrio = new_taskPrio; }

void Task::set_taskCtg(int new_taskCtg) { taskCtg = new_taskCtg; }

void Task::set_taskNote(QString new_taskNote) { taskNote = new_taskNote; }

taskPriority toTaskPriority(QString qTaskPrio)
{
    if (qTaskPrio == "LOW") return LOW;
    if (qTaskPrio == "MID") return MID;
    if (qTaskPrio == "HIGH") return HIGH;
    return LOW;
}

taskPriority toTaskPriority(std::string sTaskPrio)
{
    if (sTaskPrio == "LOW") return LOW;
    if (sTaskPrio == "MID") return MID;
    if (sTaskPrio == "HIGH") return HIGH;
    return LOW;
}
