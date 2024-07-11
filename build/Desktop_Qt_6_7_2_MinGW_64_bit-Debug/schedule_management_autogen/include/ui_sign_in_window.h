/********************************************************************************
** Form generated from reading UI file 'sign_in_window.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_IN_WINDOW_H
#define UI_SIGN_IN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sign_in_window
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *sign_in_window)
    {
        if (sign_in_window->objectName().isEmpty())
            sign_in_window->setObjectName("sign_in_window");
        sign_in_window->resize(800, 600);
        centralwidget = new QWidget(sign_in_window);
        centralwidget->setObjectName("centralwidget");
        sign_in_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(sign_in_window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        sign_in_window->setMenuBar(menubar);
        statusbar = new QStatusBar(sign_in_window);
        statusbar->setObjectName("statusbar");
        sign_in_window->setStatusBar(statusbar);

        retranslateUi(sign_in_window);

        QMetaObject::connectSlotsByName(sign_in_window);
    } // setupUi

    void retranslateUi(QMainWindow *sign_in_window)
    {
        sign_in_window->setWindowTitle(QCoreApplication::translate("sign_in_window", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sign_in_window: public Ui_sign_in_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_IN_WINDOW_H
