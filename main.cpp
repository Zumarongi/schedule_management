#include "mainwindow.h"
#include <QDebug>
#include <QApplication>
#include "sign_in_window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sign_in_window w;
    w.show();
    return a.exec();
}
