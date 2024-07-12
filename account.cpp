#include "account.h"
#include "md5.h"
#include <fstream>
#include <filesystem>
#include <QDebug>

std::vector<QString> Account::accountList = {};

std::string encrypt(QString Qplaintext)
{
    std::string plaintext = Qplaintext.toStdString();
    std::string ciphertext = MD5(plaintext).toStr();
    return ciphertext;
}

Account::Account(QString getname, QString getpassword) {
    userName=getname;
    encryptedPass=encrypt(getpassword);
    showHelp=false;
    doneAndDel=false;
}

void Account::readAccountList()
{
    std::filesystem::path acclist_path = ROOTDIR + "/data/.acclist";
    std::ifstream fin(acclist_path);
    if (!fin.is_open())
    {
        qDebug() << "./data/.acclist not found";
        return;
    }
    std::string s;
    QString qs;
    std::getline(fin, s);
    Task::setIdCounter(std::stoi(s));
    qDebug() << "IdCounter =" << Task::getIdCounter();
    accountList.clear();
    while (std::getline(fin, s))
    {
        qs = QString::fromStdString(s);
        qDebug() << qs;
        accountList.push_back(qs);
    }
    fin.close();
}

void Account::saveAccountList()
{
    std::filesystem::path acclist_path = ROOTDIR + "/data/.acclist";
    std::ofstream fout(acclist_path);
    fout << Task::getIdCounter() << std::endl;
    for (int i = 0; i < accountList.size(); i ++)
        fout << accountList[i].toStdString() << std::endl;
    fout.close();
}

bool Account::isNameExist(QString newName)
{
    qDebug() << "isNameExist";
    for (int i = 0; i < accountList.size(); i ++)
        if (accountList[i] == newName) return true;
    return false;
}

void Account::addToList(QString userName)
{
    accountList.push_back(userName);
}

void Account::saveToFile()
{
    std::filesystem::path acc_path = ROOTDIR + "/data/" + userName.toStdString() + "/.acc";
    std::ofstream fout(acc_path);
    if (!fout.is_open())
    {
        qDebug() << "fail to open .acc";
        return;
    }
    fout << userName.toStdString() << std::endl;
    fout << encryptedPass << std::endl;
    for (int i = 0; i < taskList.size(); i ++)
        fout << taskList[i]->get_taskId() << std::endl;
    fout.close();
}
