#ifndef TASK_H
#define TASK_H

#include <string>
#include <map>
#include <QMessageBox>
#include <filesystem>
#include <QPushButton>

enum taskPriority { LOW = 0, MID, HIGH };

taskPriority toTaskPriority(QString qTaskPrio);
taskPriority toTaskPriority(std::string sTaskPrio);

class Task
{
    static std::map<int, std::string> ctgIdxToStr;
    static std::map<std::string, int> ctgStrToIdx;

    static int IdCounter;
    int taskId;

    QString taskName;
    time_t stTime, edTime, rmTime;  // start, end, reminder
    QString taskLoc;                // location
    taskPriority taskPrio;
    int taskCtg;                    // catagory
    QString taskNote;
    QPushButton *taskButton;

public:
    Task(QString taskname, time_t st_time, time_t ed_time, time_t rm_time,
         QString taskloc, taskPriority taskprio, int taskctg,
         QString tasknote);         // new task
    Task(int taskId,
         QString taskname, time_t st_time, time_t ed_time, time_t rm_time,
         QString taskloc, taskPriority taskprio, int taskctg,
         QString tasknote);         // build from file
    bool saveToFile(std::filesystem::path task_path) const;
    void printInfo() const;

    static int toCtgIndex(std::string ctgStr);
    static int toCtgIndex(QString ctgqStr);
    static std::string toCtgString(int ctgIdx);

    static int getIdCounter();
    static void setIdCounter(int idcounter);

    static bool (*taskId_ascending)(const Task *, const Task *);
    static bool (*taskId_descending)(const Task *, const Task *);
    static bool (*taskName_ascending)(const Task *, const Task *);
    static bool (*taskName_descending)(const Task *, const Task *);
    static bool (*stTime_ascending)(const Task *, const Task *);
    static bool (*stTime_descending)(const Task *, const Task *);
    // rmTime_ascending/descending

    int get_taskId() const;
    QString get_taskName() const;
    time_t get_stTime() const;
    time_t get_edTime() const;
    time_t get_rmTime() const;
    QString get_taskLoc() const;
    taskPriority get_taskPrio() const;
    int get_taskCtg() const;
    QString get_taskNote() const;
    QPushButton *get_taskButton() const;

    void set_taskName(QString new_taskName);
    void set_stTime(time_t new_stTime);
    void set_edTime(time_t new_edTime);
    void set_rmTime(time_t new_rmTime);
    void set_taskLoc(QString new_taskLoc);
    void set_taskPrio(taskPriority new_taskPrio);
    void set_taskCtg(int new_taskCtg);
    void set_taskNote(QString new_taskNote);
};

#endif // TASK_H
