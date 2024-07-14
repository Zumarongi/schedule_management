#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "task.h"
#include <vector>
#include <QMessageBox>

#define ROOTDIR (std::string)"../.."

class Account
{
private:
    static std::vector<QString> accountList;

    QString userName;
    std::string encryptedPass;
    std::vector<Task *> taskList;
    bool showHelp;
    bool doneAndDel;

    static void initDataDir();
    Task *readTask(std::filesystem::path task_path);

public:
    Account(QString username);                          // Build by username, namely read from file
    Account(QString getUserName, QString getPassWord);  // Build temporarily for newly-created accounts
    ~Account();

    static void readAccountList();
    static void saveAccountList();
    static bool isNameExist(QString newName);
    static void addToList(QString userName);

    void saveToFile() const;
    void addTask(Task *taskToAdd);
    void delTask(Task *taskToDel);

    QString get_userName() const;
    std::vector<Task *> get_taskList() const;
    bool get_showHelp() const;
    bool get_doneAndDel() const;

    void set_showHelp(bool new_showHelp);
    void set_doneAndDel(bool new_doneAndDel);
};

#endif // ACCOUNT_H
