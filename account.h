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

public:
    std::vector<Task *> taskList;//暂时设为public测试使用
    bool showHelp;
    bool doneAndDel;
    Account(QString getname, QString getpassword);
    static void readAccountList();
    static void saveAccountList();
    static bool isNameExist(QString newName);
    static void addToList(QString userName);
    void readTaskList();
    void saveToFile();

    void sttimeSort();
    void nameSort();
    bool compareTime(Task *a,Task *b);
    bool compareName(Task *a,Task *b);
};

#endif // ACCOUNT_H
