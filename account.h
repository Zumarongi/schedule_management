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

    static void initDataDir();
    Task *readTask(std::filesystem::path task_path);
public:
    std::vector<Task *> taskList;//暂时设为public测试使用
    bool showHelp;
    bool doneAndDel;

    Account(QString username); // Build by username, namely read from file
    Account(QString getUserName, QString getPassWord); // Build temporarily for newly-created accounts
    ~Account();

    static void readAccountList();
    static void saveAccountList();
    static bool isNameExist(QString newName);
    static void addToList(QString userName);

    QString get_userName() const;

    void sortTask(bool (*cmp)(const Task *, const Task *));
    void saveToFile() const;
    void delTask(Task *taskToDel);
};

#endif // ACCOUNT_H
