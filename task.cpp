#include "task.h"
#include <fstream>
#include <iostream>
#include <QDebug>

std::map<int, std::string> Task::mapCtg = {{0, "学习"}, {1, "娱乐"}, {2, "生活"}, {3, "工作"}, {4, "运动"}, {5, "其他"}};

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

    taskButton=new QPushButton;
    taskButton->setFixedSize(700,40);
    taskButton->setText(taskname);
    //改变颜色
}

bool Task::saveToFile(std::filesystem::path acc_path)
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

int Task::getIdCounter() { return IdCounter; }

void Task::setIdCounter(int idcounter) { IdCounter = idcounter; }

int Task::get_taskId() const { return taskId; }

QString Task::get_taskName() const { return taskName; }

time_t Task::get_stTime() const { return stTime; }

time_t Task::get_edTime() const { return edTime; }

time_t Task::get_rmTime() const { return rmTime; }

QString Task::get_taskLoc() const { return taskLoc; }

taskPriority Task::get_taskPrio() const { return taskPrio; }

int Task::get_taskCtg() const { return taskCtg; }

QString Task::get_taskNote() const { return taskNote; }

QPushButton * Task::get_taskButton() const {return taskButton;}

void Task::mod_taskName(QString new_taskName) { taskName = new_taskName; }

void Task::mod_stTime(time_t new_stTime) { stTime = new_stTime; }

void Task::mod_edTime(time_t new_edTime) { edTime = new_edTime; }

void Task::mod_rmTime(time_t new_rmTime) { rmTime = new_rmTime; }

void Task::mod_taskLoc(QString new_taskLoc) { taskLoc = new_taskLoc; }

void Task::mod_taskPrio(taskPriority new_taskPrio) { taskPrio = new_taskPrio; }

void Task::mod_taskCtg(int new_taskCtg) { taskCtg = new_taskCtg; }

void Task::mod_taskNote(QString new_taskNote) { taskNote = new_taskNote; }

