#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "task.h"
#include<vector>

class Account
{
public:
    std::string Username;
    std::string encryptedPass;
    std::vector<Task *> taskList;
    bool showHelp;
    bool doneAndDel;

    Account();
};

#endif // ACCOUNT_H
