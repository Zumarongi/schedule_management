#ifndef TASK_H
#define TASK_H

#include <string>
#include <map>
#include <QMessageBox>
#include <filesystem>
#include <QPushButton>
#include <QDateTime>

enum TaskPriority { LOW = 0, MID, HIGH };

TaskPriority toTaskPriority(QString qTaskPrio);
TaskPriority toTaskPriority(std::string sTaskPrio);
QString toQString(TaskPriority taskPrio);
std::string toString(TaskPriority taskPrio);

class Task
{
    static std::map<int, std::string> ctgIdxToStr;
    static std::map<std::string, int> ctgStrToIdx;

    static int IdCounter;
    int taskId;

    QString taskName;
    QDateTime stTime, edTime;
    QTime rmTime;
    QString taskLoc;                // location
    TaskPriority taskPrio;          // priority
    int taskCtg;                    // catagory
    QString taskNote;
    QPushButton *taskButton;

public:
    Task(QString taskname, QDateTime st_time, QDateTime ed_time, QTime rm_time,
         QString taskloc, TaskPriority taskprio, int taskctg,
         QString tasknote);         // new task
    Task(int taskId,
         QString taskname, QDateTime st_time, QDateTime ed_time, QTime rm_time,
         QString taskloc, TaskPriority taskprio, int taskctg,
         QString tasknote);         // build from file
    ~Task();
    bool saveToFile(std::filesystem::path task_path) const;
    void printInfo() const;

    static int toCtgIndex(std::string ctgStr);
    static int toCtgIndex(QString ctgqStr);
    static std::string toCtgString(int ctgIdx);
    static QString toCtgQString(int ctgIdx);

    static int getIdCounter();
    static void setIdCounter(int idcounter);

    static void sortTasks(std::vector<Task *>::iterator begin, std::vector<Task *>::iterator end, bool (*cmp)(const Task *, const Task *));
    static bool (*taskId_ascending)(const Task *, const Task *);
    static bool (*taskId_descending)(const Task *, const Task *);
    static bool (*taskName_ascending)(const Task *, const Task *);
    static bool (*taskName_descending)(const Task *, const Task *);
    static bool (*stTime_ascending)(const Task *, const Task *);
    static bool (*stTime_descending)(const Task *, const Task *);

    int get_taskId() const;
    QString get_taskName() const;
    QDateTime get_stTime() const;
    QDateTime get_edTime() const;
    QTime get_rmTime() const;
    QString get_taskLoc() const;
    TaskPriority get_taskPrio() const;
    int get_taskCtg() const;
    QString get_taskNote() const;
    QPushButton *get_taskButton() const;

    void set_taskName(QString new_taskName);
    void set_stTime(QDateTime new_stTime);
    void set_edTime(QDateTime new_edTime);
    void set_rmTime(QTime new_rmTime);
    void set_taskLoc(QString new_taskLoc);
    void set_taskPrio(TaskPriority new_taskPrio);
    void set_taskCtg(int new_taskCtg);
    void set_taskNote(QString new_taskNote);
};

#endif // TASK_H
