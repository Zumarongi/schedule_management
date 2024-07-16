#include "create_task_window.h"
#include "mainwindow.h"
#include "sign_in_window.h"
#include "task_info_window.h"
#include <QDebug>
#include <QApplication>

Account *currentAccount;
MainWindow *mainPage;
create_task_window *createTaskPage;
task_info_window *taskInfoPage;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sign_in_window w;
    w.show();
    int ret = a.exec();
    delete currentAccount;
    delete mainPage;
    return ret;
}
