/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit_search;
    QPushButton *search_button;
    QPushButton *add_task_button;
    QLabel *not_find_warning;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *change_order_button;
    QCheckBox *auto_delete;
    QRadioButton *time_order_button;
    QRadioButton *name_order_button;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit_search = new QLineEdit(centralwidget);
        lineEdit_search->setObjectName("lineEdit_search");
        lineEdit_search->setGeometry(QRect(130, 20, 181, 21));
        search_button = new QPushButton(centralwidget);
        search_button->setObjectName("search_button");
        search_button->setGeometry(QRect(230, 20, 80, 20));
        add_task_button = new QPushButton(centralwidget);
        add_task_button->setObjectName("add_task_button");
        add_task_button->setGeometry(QRect(340, 20, 80, 20));
        not_find_warning = new QLabel(centralwidget);
        not_find_warning->setObjectName("not_find_warning");
        not_find_warning->setGeometry(QRect(130, 40, 181, 21));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 60, 431, 351));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 429, 349));
        scrollArea->setWidget(scrollAreaWidgetContents);
        change_order_button = new QPushButton(centralwidget);
        change_order_button->setObjectName("change_order_button");
        change_order_button->setGeometry(QRect(30, 40, 80, 20));
        auto_delete = new QCheckBox(centralwidget);
        auto_delete->setObjectName("auto_delete");
        auto_delete->setGeometry(QRect(30, 20, 68, 19));
        time_order_button = new QRadioButton(centralwidget);
        time_order_button->setObjectName("time_order_button");
        time_order_button->setGeometry(QRect(10, 0, 81, 19));
        name_order_button = new QRadioButton(centralwidget);
        name_order_button->setObjectName("name_order_button");
        name_order_button->setGeometry(QRect(100, 0, 81, 19));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        search_button->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        add_task_button->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        not_find_warning->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        change_order_button->setText(QCoreApplication::translate("MainWindow", "\346\224\271\345\217\230\351\241\272\345\272\217", nullptr));
        auto_delete->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\345\210\240\351\231\244\344\273\273\345\212\241", nullptr));
        time_order_button->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\227\266\351\227\264\351\241\272\345\272\217", nullptr));
        name_order_button->setText(QCoreApplication::translate("MainWindow", "\345\220\215\345\255\227\351\241\272\345\272\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
