#ifndef TASK_H
#define TASK_H

#include <string>
#include <map>
#include <QMessageBox>
#include <filesystem>

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
    bool saveToFile(std::filesystem::path task_path);
    void printInfo();

    static int getIdCounter();
    static void setIdCounter(int idcounter);

    int get_taskId() const;
    QString get_taskName() const;
    time_t get_stTime() const;
    time_t get_edTime() const;
    time_t get_rmTime() const;
    QString get_taskLoc() const;
    taskPriority get_taskPrio() const;
    int get_taskCtg() const;
    QString get_taskNote() const;

    void mod_taskName(QString new_taskName);
    void mod_stTime(time_t new_stTime);
    void mod_edTime(time_t new_edTime);
    void mod_rmTime(time_t new_rmTime);
    void mod_taskLoc(QString new_taskLoc);
    void mod_taskPrio(taskPriority new_taskPrio);
    void mod_taskCtg(int new_taskCtg);
    void mod_taskNote(QString new_taskNote);
};

#endif // TASK_H
