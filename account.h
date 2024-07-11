#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "task.h"
#include<vector>
#include <QMessageBox>

class Account
{
public:
    QString Username;
    QString encryptedPass;
    std::vector<Task *> taskList;
    bool showHelp;
    bool doneAndDel;

    Account(QString getname,QString getpassword);
    static std::vector<Account *> accountLists;
};


#endif // ACCOUNT_H
