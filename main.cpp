#include "mainwindow.h"
#include <QDebug>
#include <QApplication>
#include "sign_in_window.h"


MainWindow *mainPage;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sign_in_window w;
    w.show();
    MainWindow::connect(mainPage,&MainWindow::reload,[=](){
        mainPage=new MainWindow;
        mainPage->show();
    });
    return a.exec();
}
