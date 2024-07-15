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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QCheckBox *auto_delete;
    QLabel *label_from;
    QDateTimeEdit *min_dateTimeEdit;
    QLabel *label_to;
    QDateTimeEdit *max_dateTimeEdit;
    QComboBox *choose_order;
    QComboBox *choose_priority;
    QComboBox *choose_category;
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
        not_find_warning->setGeometry(QRect(130, 40, 181, 16));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 110, 431, 301));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 429, 299));
        scrollArea->setWidget(scrollAreaWidgetContents);
        auto_delete = new QCheckBox(centralwidget);
        auto_delete->setObjectName("auto_delete");
        auto_delete->setGeometry(QRect(10, 410, 68, 19));
        label_from = new QLabel(centralwidget);
        label_from->setObjectName("label_from");
        label_from->setGeometry(QRect(10, 60, 16, 16));
        min_dateTimeEdit = new QDateTimeEdit(centralwidget);
        min_dateTimeEdit->setObjectName("min_dateTimeEdit");
        min_dateTimeEdit->setGeometry(QRect(30, 60, 194, 22));
        label_to = new QLabel(centralwidget);
        label_to->setObjectName("label_to");
        label_to->setGeometry(QRect(230, 60, 16, 16));
        max_dateTimeEdit = new QDateTimeEdit(centralwidget);
        max_dateTimeEdit->setObjectName("max_dateTimeEdit");
        max_dateTimeEdit->setGeometry(QRect(250, 60, 194, 22));
        choose_order = new QComboBox(centralwidget);
        choose_order->setObjectName("choose_order");
        choose_order->setGeometry(QRect(70, 90, 62, 22));
        choose_priority = new QComboBox(centralwidget);
        choose_priority->setObjectName("choose_priority");
        choose_priority->setGeometry(QRect(190, 90, 62, 22));
        choose_category = new QComboBox(centralwidget);
        choose_category->setObjectName("choose_category");
        choose_category->setGeometry(QRect(320, 90, 62, 22));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        search_button->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        add_task_button->setText(QCoreApplication::translate("MainWindow", "\345\210\233\345\273\272\344\273\273\345\212\241", nullptr));
        not_find_warning->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        auto_delete->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\345\210\240\351\231\244\344\273\273\345\212\241", nullptr));
        label_from->setText(QCoreApplication::translate("MainWindow", "\344\273\216", nullptr));
        label_to->setText(QCoreApplication::translate("MainWindow", "\345\210\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
