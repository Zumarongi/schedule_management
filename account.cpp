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
    qDebug() << "[File" << task_path.string() << "opened to read.]";
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

    fin.close();
    qDebug() << "[File" << task_path.string() << "opened.]";

    return new Task(taskId, taskName, stTime, edTime, rmTime, taskLoc, taskPrio, taskCtg, taskNote);
}

Account::Account(QString username)
{
    std::filesystem::path acc_dir = ROOTDIR + "/data/" + username.toStdString();
    std::filesystem::path accfile_path = ROOTDIR + "/data/" + username.toStdString() + "/.acc";
    std::ifstream fin(accfile_path);
    if (!fin.is_open())
    {
        qDebug() << "can't find account" << username;
        return;
    }
    qDebug() << "[File" << accfile_path.string() << "opened to read.]";
    std::string s;
    std::getline(fin, s);
    userName = username;
    std::getline(fin, s);
    encryptedPass = s;
    std::getline(fin, s);
    doneAndDel = s != "0";
    qDebug() << "Reading from file doneAndDel =" << doneAndDel;
    taskList.clear();
    while (std::getline(fin, s))
    {
        std::filesystem::path task_path = ROOTDIR + "/data/" + username.toStdString() + "/" + s + ".task";
        Task *t = readTask(task_path);
        if (t != nullptr)
            taskList.push_back(t);
    }
    Task::sortTasks(taskList.begin(), taskList.end(), Task::stTime_ascending);
    fin.close();
    qDebug() << "[File" << accfile_path.string() << "closed.]";
}

Account::Account(QString getUserName, QString getPassWord) {
    userName=getUserName;
    encryptedPass=encrypt(getPassWord);
    qDebug() << "sign-up password :" << getPassWord;
    qDebug() << "sign-up password encrypted :" << encryptedPass;
    showHelp=false;
    doneAndDel=false;
}

Account::~Account()
{
    Task *p;
    for (auto task: taskList)
        delete task;
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
    qDebug() << "[File" << acclist_path.string() << "opened to read.]";
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
    qDebug() << "[File" << acclist_path.string() << "closed.]";
}

void Account::saveAccountList()
{
    std::filesystem::path acclist_path = ROOTDIR + "/data/.acclist";
    std::ofstream fout(acclist_path);
    qDebug() << "[File" << acclist_path.string() << "opened to write.]";
    fout << Task::getIdCounter() << std::endl;
    for (int i = 0; i < accountList.size(); i ++)
        fout << accountList[i].toStdString() << std::endl;
    fout.close();
    qDebug() << "[File" << acclist_path.string() << "closed.]";
}

bool Account::isNameExist(QString newName)
{
    qDebug() << "isNameExist";
    for (auto &userName: accountList)
        if (userName == newName) return true;
    return false;
}

void Account::addToList(QString userName)
{
    accountList.push_back(userName);
}

QString Account::get_userName() const { return userName; }

std::vector<Task *> Account::get_taskList() const { return taskList; }

bool Account::get_showHelp() const { return showHelp; }

bool Account::get_doneAndDel() const { return doneAndDel; }

void Account::set_showHelp(bool new_showHelp) { showHelp = new_showHelp; }

void Account::set_doneAndDel(bool new_doneAndDel) { doneAndDel = new_doneAndDel; }

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
    qDebug() << "[File" << acc_path.string() << "opened to write.]";
    fout << userName.toStdString() << std::endl;
    fout << encryptedPass << std::endl;
    fout << (int)doneAndDel << std::endl;
    qDebug() << "Saving to file doneAndDel =" << doneAndDel;
    for (int i = 0; i < taskList.size(); i ++)
        fout << taskList[i]->get_taskId() << std::endl;
    fout.close();
    qDebug() << "[File" << acc_path.string() << "closed.]";
}

void Account::addTask(Task *taskToAdd)
{
    taskList.push_back(taskToAdd);

    std::filesystem::path task_path = ROOTDIR + "/data/" + userName.toStdString() + "/" + std::to_string(taskToAdd->get_taskId()) + ".task";
    taskToAdd->saveToFile(task_path);

    saveToFile();
}

void Account::delTask(Task *taskToDel)
{
    for (auto p = taskList.begin(); p != taskList.end(); p ++)
        if (taskToDel->get_taskId() == (*p)->get_taskId())
        {
            taskList.erase(p);

            std::filesystem::path task_path = ROOTDIR + "/data/" + this->userName.toStdString() + "/" + std::to_string(taskToDel->get_taskId()) + ".task";
            std::filesystem::remove(task_path);

            delete taskToDel;
            break;
        }
    saveToFile();
}

void Account::printTask() const
{
    qDebug() << "printTask(): printing taskIds";
    for (auto task: taskList)
        qDebug() << task->get_taskId() << "\t" << task->get_taskName();
}
