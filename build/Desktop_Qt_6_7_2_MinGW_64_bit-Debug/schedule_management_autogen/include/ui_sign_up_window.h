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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sign_up_window
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QPushButton *sign_up_button;
    QPushButton *cancel_button;
    QLabel *username_warning;
    QLabel *conf_warning;
    QLineEdit *lineEdit_confirm_password;
    QLabel *emptyID_warning;
    QLabel *emptypw_warning;
    QLabel *empty_confpw_warning;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *sign_up_window)
    {
        if (sign_up_window->objectName().isEmpty())
            sign_up_window->setObjectName("sign_up_window");
        sign_up_window->resize(800, 600);
        centralwidget = new QWidget(sign_up_window);
        centralwidget->setObjectName("centralwidget");
        lineEdit_username = new QLineEdit(centralwidget);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(140, 70, 161, 31));
        lineEdit_password = new QLineEdit(centralwidget);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(140, 120, 161, 31));
        sign_up_button = new QPushButton(centralwidget);
        sign_up_button->setObjectName("sign_up_button");
        sign_up_button->setGeometry(QRect(110, 260, 80, 20));
        cancel_button = new QPushButton(centralwidget);
        cancel_button->setObjectName("cancel_button");
        cancel_button->setGeometry(QRect(270, 260, 80, 20));
        username_warning = new QLabel(centralwidget);
        username_warning->setObjectName("username_warning");
        username_warning->setGeometry(QRect(140, 100, 161, 16));
        username_warning->setAutoFillBackground(false);
        username_warning->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"background-color: rgb(255, 0, 0);\n"
"background-color: rgb(255, 0, 0);\n"
"background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        conf_warning = new QLabel(centralwidget);
        conf_warning->setObjectName("conf_warning");
        conf_warning->setGeometry(QRect(140, 200, 161, 16));
        conf_warning->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 0, 0);"));
        lineEdit_confirm_password = new QLineEdit(centralwidget);
        lineEdit_confirm_password->setObjectName("lineEdit_confirm_password");
        lineEdit_confirm_password->setGeometry(QRect(140, 170, 161, 31));
        emptyID_warning = new QLabel(centralwidget);
        emptyID_warning->setObjectName("emptyID_warning");
        emptyID_warning->setGeometry(QRect(140, 100, 161, 16));
        emptyID_warning->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        emptypw_warning = new QLabel(centralwidget);
        emptypw_warning->setObjectName("emptypw_warning");
        emptypw_warning->setGeometry(QRect(140, 150, 161, 16));
        emptypw_warning->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        empty_confpw_warning = new QLabel(centralwidget);
        empty_confpw_warning->setObjectName("empty_confpw_warning");
        empty_confpw_warning->setGeometry(QRect(140, 200, 161, 16));
        empty_confpw_warning->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 0, 0);"));
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
        lineEdit_username->setPlaceholderText(QCoreApplication::translate("sign_up_window", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("sign_up_window", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        sign_up_button->setText(QCoreApplication::translate("sign_up_window", "\346\263\250\345\206\214", nullptr));
        cancel_button->setText(QCoreApplication::translate("sign_up_window", "\345\217\226\346\266\210", nullptr));
        username_warning->setText(QCoreApplication::translate("sign_up_window", "\347\224\250\346\210\267\345\220\215\345\267\262\345\255\230\345\234\250\357\274\201", nullptr));
        conf_warning->setText(QCoreApplication::translate("sign_up_window", "\345\257\206\347\240\201\344\270\215\347\233\270\345\220\214\357\274\201", nullptr));
        lineEdit_confirm_password->setPlaceholderText(QCoreApplication::translate("sign_up_window", "\350\257\267\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        emptyID_warning->setText(QCoreApplication::translate("sign_up_window", "\347\224\250\346\210\267\345\220\215\344\270\215\350\203\275\344\270\272\347\251\272\357\274\201", nullptr));
        emptypw_warning->setText(QCoreApplication::translate("sign_up_window", "\345\257\206\347\240\201\344\270\215\350\203\275\344\270\272\347\251\272\357\274\201", nullptr));
        empty_confpw_warning->setText(QCoreApplication::translate("sign_up_window", "\350\257\267\347\241\256\350\256\244\345\257\206\347\240\201\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sign_up_window: public Ui_sign_up_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_UP_WINDOW_H
