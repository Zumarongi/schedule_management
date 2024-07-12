#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "task.h"
#include <vector>
#include <QMessageBox>

#define ROOTDIR (std::string)"../../.."

class Account
{
private:
    static std::vector<QString> accountList;

    QString userName;
    std::string encryptedPass;
    std::vector<Task *> taskList;
    bool showHelp;
    bool doneAndDel;

public:
    Account(QString getname, QString getpassword);
    static void readAccountList();
    static void saveAccountList();
    static bool isNameExist(QString newName);
    static void addToList(QString userName);
    void readTaskList();
    void saveToFile();
};

#endif // ACCOUNT_H
