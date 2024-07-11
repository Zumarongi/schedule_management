#include "account.h"

Account::Account(QString getname,QString getpassword) {
    Username=getname;
    encryptedPass=getpassword;
    showHelp=false;
    doneAndDel=false;
}

std::vector<Account *> Account::accountLists={};
