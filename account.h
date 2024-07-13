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
    Account(QString username); // Build by username, namely read from file
    Account(QString getUserName, QString getPassWord); // Build temporarily for newly-created accounts

    static void readAccountList();
    static void saveAccountList();
    static bool isNameExist(QString newName);
    static void addToList(QString userName);

    void sortTask(bool (*cmp)(const Task *, const Task *));
    void saveToFile();
};

#endif // ACCOUNT_H
