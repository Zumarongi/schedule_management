#include "task.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <QDebug>

std::map<int, std::string> Task::ctgIdxToStr = {{1, "学习"}, {2, "娱乐"}, {3, "生活"}, {4, "工作"}, {5, "运动"}, {6, "其他"}};
std::map<std::string, int> Task::ctgStrToIdx = {{"学习", 1}, {"娱乐", 2}, {"生活", 3}, {"工作", 4}, {"运动", 5}, {"其他", 6}};

int Task::IdCounter = 0;

Task::Task(QString taskname, QDateTime st_time, QDateTime ed_time, QTime rm_time,
           QString taskloc, TaskPriority taskprio, int taskctg,
           QString tasknote)
{
    taskId = ++ IdCounter;
    taskName = taskname;
    stTime = st_time;
    edTime = ed_time;
    rmTime = rm_time;
    taskLoc = taskloc;
    taskPrio = taskprio;
    taskCtg = taskctg;
    taskNote = tasknote;
    isReminded = false;
}

Task::Task(int taskid,
           QString taskname, QDateTime st_time, QDateTime ed_time, QTime rm_time,
           QString taskloc, TaskPriority taskprio, int taskctg,
           QString tasknote, bool isreminded)
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
    isReminded = isreminded;
}

Task::~Task() {}

bool Task::saveToFile(std::filesystem::path task_path) const
{
    qDebug() << "Task" << this->get_taskId() << "calling Task::saveTofile(), saving to" << task_path.string();
    std::ofstream fout(task_path);
    if (!fout.is_open())
    {
        qDebug() << "Can't open file" << task_path.string();
        return false;
    }
    qDebug() << "[File" << task_path.string() << "opened to write.]";
    fout << taskId << std::endl;
    fout << taskName.toStdString() << std::endl;
    fout << stTime.toString().toStdString() << std::endl;
    fout << edTime.toString().toStdString() << std::endl;
    fout << rmTime.toString().toStdString() << std::endl;
    fout << taskLoc.toStdString() << std::endl;
    fout << (int)taskPrio << std::endl;
    fout << taskCtg << std::endl;
    fout << taskNote.toStdString() << std::endl;
    fout << (int)isReminded <<std::endl;
    fout.close();
    qDebug() << "[File" << task_path.string() << "closed.]";
    return true;
}

int Task::toCtgIndex(std::string ctgStr) { return ctgStrToIdx[ctgStr]; }

int Task::toCtgIndex(QString ctgqStr) { return ctgStrToIdx[ctgqStr.toStdString()]; }

std::string Task::toCtgString(int ctgIdx) { return ctgIdxToStr[ctgIdx]; }

QString Task::toCtgQString(int ctgIdx) { return QString::fromStdString(ctgIdxToStr[ctgIdx]); }

int Task::getIdCounter() { return IdCounter; }

void Task::setIdCounter(int idcounter) { IdCounter = idcounter; }

void Task::sortTasks(std::vector<Task *>::iterator begin, std::vector<Task *>::iterator end, bool (*cmp)(const Task *, const Task *) = Task::stTime_ascending)
{
    std::stable_sort(begin, end, cmp);
}

bool (*Task::taskId_ascending)(const Task *, const Task *) = [](const Task *x, const Task *y) -> bool { return x->taskId < y->taskId; };

bool (*Task::taskId_descending)(const Task *, const Task *) = [](const Task *x, const Task *y) -> bool { return x->taskId > y->taskId; };

bool (*Task::taskName_ascending)(const Task *, const Task *) = [](const Task *x, const Task *y) -> bool { return x->taskName < y->taskName; };

bool (*Task::taskName_descending)(const Task *, const Task *) = [](const Task *x, const Task *y) -> bool { return x->taskName > y->taskName; };

bool (*Task::stTime_ascending)(const Task *, const Task *) = [](const Task *x, const Task *y) -> bool { return x->stTime < y->stTime; };

bool (*Task::stTime_descending)(const Task *, const Task *) = [](const Task *x, const Task *y) -> bool { return x->stTime > y->stTime; };

int Task::get_taskId() const { return taskId; }

QString Task::get_taskName() const { return taskName; }

QDateTime Task::get_stTime() const { return stTime; }

QDateTime Task::get_edTime() const { return edTime; }

QTime Task::get_rmTime() const { return rmTime; }

QString Task::get_taskLoc() const { return taskLoc; }

TaskPriority Task::get_taskPrio() const { return taskPrio; }

int Task::get_taskCtg() const { return taskCtg; }

QString Task::get_taskNote() const { return taskNote; }

bool Task::get_isReminded() const { return isReminded; }

void Task::set_taskName(QString new_taskName) { taskName = new_taskName; }

void Task::set_stTime(QDateTime new_stTime) { stTime = new_stTime; }

void Task::set_edTime(QDateTime new_edTime) { edTime = new_edTime; }

void Task::set_rmTime(QTime new_rmTime) { rmTime = new_rmTime; }

void Task::set_taskLoc(QString new_taskLoc) { taskLoc = new_taskLoc; }

void Task::set_taskPrio(TaskPriority new_taskPrio) { taskPrio = new_taskPrio; }

void Task::set_taskCtg(int new_taskCtg) { taskCtg = new_taskCtg; }

void Task::set_taskNote(QString new_taskNote) { taskNote = new_taskNote; }

void Task::set_isReminded(bool new_isReminded) { isReminded = new_isReminded; }

TaskPriority toTaskPriority(QString qTaskPrio)
{
    if (qTaskPrio == "低" || qTaskPrio == "LOW" || qTaskPrio == "1") return LOW;
    if (qTaskPrio == "中" || qTaskPrio == "MID" || qTaskPrio == "2") return MID;
    if (qTaskPrio == "高" || qTaskPrio == "HIGH" || qTaskPrio == "3") return HIGH;
    return LOW;
}

TaskPriority toTaskPriority(std::string sTaskPrio)
{
    if (sTaskPrio == "低" || sTaskPrio == "LOW" || sTaskPrio == "1") return LOW;
    if (sTaskPrio == "中" || sTaskPrio == "MID" || sTaskPrio == "2") return MID;
    if (sTaskPrio == "高" || sTaskPrio == "HIGH" || sTaskPrio == "3") return HIGH;
    return LOW;
}

QString toQString(TaskPriority taskPrio)
{
    if (taskPrio == LOW) return "低";
    if (taskPrio == MID) return "中";
    if (taskPrio == HIGH) return "高";
    return "低";
}

std::string toString(TaskPriority taskPrio)
{
    if (taskPrio == LOW) return "低";
    if (taskPrio == MID) return "中";
    if (taskPrio == HIGH) return "高";
    return "低";
}
