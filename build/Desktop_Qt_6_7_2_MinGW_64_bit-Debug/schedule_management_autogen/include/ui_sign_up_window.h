/********************************************************************************
** Form generated from reading UI file 'sign_up_window.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_UP_WINDOW_H
#define UI_SIGN_UP_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sign_up_window
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *sign_up_window)
    {
        if (sign_up_window->objectName().isEmpty())
            sign_up_window->setObjectName("sign_up_window");
        sign_up_window->resize(800, 600);
        centralwidget = new QWidget(sign_up_window);
        centralwidget->setObjectName("centralwidget");
        sign_up_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(sign_up_window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        sign_up_window->setMenuBar(menubar);
        statusbar = new QStatusBar(sign_up_window);
        statusbar->setObjectName("statusbar");
        sign_up_window->setStatusBar(statusbar);

        retranslateUi(sign_up_window);

        QMetaObject::connectSlotsByName(sign_up_window);
    } // setupUi

    void retranslateUi(QMainWindow *sign_up_window)
    {
        sign_up_window->setWindowTitle(QCoreApplication::translate("sign_up_window", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sign_up_window: public Ui_sign_up_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_UP_WINDOW_H
