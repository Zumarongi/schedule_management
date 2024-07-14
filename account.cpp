#include "account.h"
#include "md5.h"
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <QDebug>

std::vector<QString> Account::accountList = {};

std::string encrypt(QString Qplaintext)
{
    std::string plaintext = Qplaintext.toStdString();
    std::string ciphertext = MD5(plaintext).toStr();
    return ciphertext;
}

void Account::initDataDir()
{
    std::filesystem::create_directories(ROOTDIR + "/data/");
    std::ofstream fout(ROOTDIR + "/data/.acclist");
    fout << 0;
}

Task *Account::readTask(std::filesystem::path task_path)
{
    qDebug() << this->userName << "calling readTask(task_path =" << QString::fromStdString(task_path.string()) << ")";
    std::ifstream fin(task_path);
    if (!fin.is_open())
    {
        qDebug() << "File" << QString::fromStdString(task_path.string()) << "not found";
        return nullptr;
    }
    std::string s;

    getline(fin, s);
    int taskId = std::stoi(s);

    getline(fin, s);
    QString taskName = QString::fromStdString(s);

    getline(fin, s);
    QDateTime stTime = QDateTime::fromString(QString::fromStdString(s));

    getline(fin, s);
    QDateTime edTime = QDateTime::fromString(QString::fromStdString(s));

    getline(fin, s);
    QTime rmTime = QTime::fromString(QString::fromStdString(s));

    getline(fin, s);
    QString taskLoc = QString::fromStdString(s);

    getline(fin, s);
    TaskPriority taskPrio = toTaskPriority(s);

    getline(fin, s);
    int taskCtg = std::stoi(s);

    getline(fin, s);
    QString taskNote = QString::fromStdString(s);

    return new Task(taskId, taskName, stTime, edTime, rmTime, taskLoc, taskPrio, taskCtg, taskNote);
}

Account::Account(QString username)
{
    userName = username;
    std::filesystem::path acc_dir = ROOTDIR + "/data/" + username.toStdString();
    std::ifstream fin(acc_dir.append("/.acc"));
    if (!fin.is_open())
    {
        qDebug() << "can't find account" << username;
        return;
    }
    std::string s;
    std::getline(fin, s);
    std::getline(fin, s);
    encryptedPass = s;
    taskList.clear();
    while (std::getline(fin, s))
    {
        Task *t = readTask(acc_dir.append("/" + s + "/.task"));
        if (t != nullptr)
            taskList.push_back(t);
    }
    sortTask(taskList,Task::stTime_ascending);
    fin.close();
    showHelp=false;
    doneAndDel=false;
    maxTime=time(NULL);
    minTime=0;
}

Account::Account(QString getUserName, QString getPassWord) {
    userName=getUserName;
    encryptedPass=encrypt(getPassWord);
    showHelp=false;
    doneAndDel=false;
}

Account::~Account()
{
    Task *p;
}

void Account::readAccountList()
{
    std::filesystem::path acclist_path = ROOTDIR + "/data/.acclist";
    std::ifstream fin(acclist_path);
    if (!fin.is_open())
    {
        qDebug() << "File ./data/.acclist not found.";
        initDataDir();
        qDebug() << "Path ./data/.acclist created.";
        return;
    }
    std::string s;
    QString qs;
    std::getline(fin, s);
    Task::setIdCounter(std::stoi(s));
    accountList.clear();
    while (std::getline(fin, s))
    {
        qs = QString::fromStdString(s);
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

QString Account::get_userName() const { return userName; }

void Account::sortTask(bool (*cmp)(const Task *, const Task *) = Task::stTime_ascending)
{
    std::stable_sort(taskList.begin(), taskList.end(), cmp);
}

void Account::saveToFile() const
{
    qDebug() << this->userName << "calling saveToFile()";
    std::filesystem::path acc_path = ROOTDIR + "/data/" + userName.toStdString() + "/.acc";
    std::ofstream fout(acc_path);
    if (!fout.is_open())
    {
        qDebug() << "Fail to open" << QString::fromStdString(acc_path.string());
        return;
    }
    fout << userName.toStdString() << std::endl;
    fout << encryptedPass << std::endl;
    for (int i = 0; i < taskList.size(); i ++)
        fout << taskList[i]->get_taskId() << std::endl;
    fout.close();
}

void Account::delTask(Task *taskToDel)
{
    for (auto p = taskList.begin(); p != taskList.end(); p ++)
        if (taskToDel == *p)
        {
            taskList.erase(p);

            std::filesystem::path task_path = ROOTDIR + "/data/" + this->userName.toStdString() + "/" + std::to_string( taskToDel->get_taskId()) + ".task";
            std::filesystem::remove(task_path);

            taskToDel->~Task();
            break;
        }
    saveToFile();
}
