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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sign_in_window
{
public:
    QWidget *centralwidget;
    QPushButton *sign_in_Button;
    QPushButton *sign_up_button;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QLabel *empty_username_warning;
    QLabel *empty_password_warning;
    QLabel *notfind_username_warning;
    QLabel *error_password_warning;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *sign_in_window)
    {
        if (sign_in_window->objectName().isEmpty())
            sign_in_window->setObjectName("sign_in_window");
        sign_in_window->resize(800, 600);
        centralwidget = new QWidget(sign_in_window);
        centralwidget->setObjectName("centralwidget");
        sign_in_Button = new QPushButton(centralwidget);
        sign_in_Button->setObjectName("sign_in_Button");
        sign_in_Button->setGeometry(QRect(100, 260, 80, 20));
        sign_up_button = new QPushButton(centralwidget);
        sign_up_button->setObjectName("sign_up_button");
        sign_up_button->setGeometry(QRect(260, 260, 80, 20));
        lineEdit_username = new QLineEdit(centralwidget);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(140, 120, 161, 31));
        lineEdit_password = new QLineEdit(centralwidget);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(140, 180, 161, 31));
        empty_username_warning = new QLabel(centralwidget);
        empty_username_warning->setObjectName("empty_username_warning");
        empty_username_warning->setGeometry(QRect(140, 150, 161, 16));
        empty_username_warning->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        empty_password_warning = new QLabel(centralwidget);
        empty_password_warning->setObjectName("empty_password_warning");
        empty_password_warning->setGeometry(QRect(140, 210, 161, 16));
        empty_password_warning->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 0, 0);"));
        notfind_username_warning = new QLabel(centralwidget);
        notfind_username_warning->setObjectName("notfind_username_warning");
        notfind_username_warning->setGeometry(QRect(140, 150, 161, 16));
        notfind_username_warning->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 0, 0);"));
        error_password_warning = new QLabel(centralwidget);
        error_password_warning->setObjectName("error_password_warning");
        error_password_warning->setGeometry(QRect(140, 210, 161, 16));
        error_password_warning->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 0, 0);"));
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
        sign_in_Button->setText(QCoreApplication::translate("sign_in_window", "\347\231\273\345\275\225", nullptr));
        sign_up_button->setText(QCoreApplication::translate("sign_in_window", "\346\263\250\345\206\214", nullptr));
        lineEdit_username->setPlaceholderText(QCoreApplication::translate("sign_in_window", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("sign_in_window", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        empty_username_warning->setText(QCoreApplication::translate("sign_in_window", "\350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\347\224\250\346\210\267\345\220\215\357\274\201", nullptr));
        empty_password_warning->setText(QCoreApplication::translate("sign_in_window", "\350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\345\257\206\347\240\201\357\274\201", nullptr));
        notfind_username_warning->setText(QCoreApplication::translate("sign_in_window", "\347\224\250\346\210\267\345\220\215\344\270\215\345\255\230\345\234\250\357\274\201", nullptr));
        error_password_warning->setText(QCoreApplication::translate("sign_in_window", "\345\257\206\347\240\201\344\270\215\346\255\243\347\241\256\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sign_in_window: public Ui_sign_in_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_IN_WINDOW_H
