#ifndef TASK_H
#define TASK_H

#include<string>
#include<map>

enum taskPriority { LOW = 0, MID, HIGH };

class Task
{
    static std::map<int, std::string> mapCtg;

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

    std::string get_taskName() const;
    time_t get_stTime() const;
    time_t get_edTime() const;
    time_t get_rmTime() const;
    std::string get_taskLoc() const;
    taskPriority get_taskPrio() const;
    int get_taskCtg() const;
    std::string get_taskNote() const;

    void mod_taskName(std::string new_taskName);
    void mod_stTime(time_t new_stTime);
    void mod_edTime(time_t new_edTime);
    void mod_rmTime(time_t new_rmTime);
    void mod_taskLoc(std::string new_taskLoc);
    void mod_taskPrio(taskPriority new_taskPrio);
    void mod_taskCtg(int new_taskCtg);
    void mod_taskNote(std::string new_taskNote);

};

#endif // TASK_H
