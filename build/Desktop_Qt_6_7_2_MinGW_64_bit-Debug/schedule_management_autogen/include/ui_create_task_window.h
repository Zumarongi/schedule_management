/********************************************************************************
** Form generated from reading UI file 'create_task_window.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_TASK_WINDOW_H
#define UI_CREATE_TASK_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_create_task_window
{
public:
    QLabel *label_rmTime_h;
    QComboBox *comboBox_taskPrio;
    QLabel *label_taskLoc;
    QLabel *label_taskName;
    QLineEdit *lineEdit_taskName;
    QLabel *label_taskPrio;
    QTextEdit *textEdit_taskNote;
    QLabel *label_edTime;
    QPushButton *pushButton_createTask;
    QLabel *warning_rmTimeTooEarly;
    QLineEdit *lineEdit_taskLoc;
    QLabel *label_taskNote;
    QLabel *label_rmTime_m;
    QComboBox *comboBox_taskCtg;
    QLabel *warning_taskNameEmpty;
    QLineEdit *lineEdit_rmTime_m;
    QLabel *label_taskCtg;
    QDateTimeEdit *dateTimeEdit_stTime;
    QLabel *label_stTime;
    QDateTimeEdit *dateTimeEdit_edTime;
    QLabel *label_rmTime;
    QLineEdit *lineEdit_rmTime_h;
    QPushButton *pushButton_cancel;
    QLabel *warning_edTimeTooEarly;

    void setupUi(QWidget *create_task_window)
    {
        if (create_task_window->objectName().isEmpty())
            create_task_window->setObjectName("create_task_window");
        create_task_window->resize(600, 400);
        label_rmTime_h = new QLabel(create_task_window);
        label_rmTime_h->setObjectName("label_rmTime_h");
        label_rmTime_h->setGeometry(QRect(110, 150, 30, 20));
        comboBox_taskPrio = new QComboBox(create_task_window);
        comboBox_taskPrio->addItem(QString());
        comboBox_taskPrio->addItem(QString());
        comboBox_taskPrio->addItem(QString());
        comboBox_taskPrio->setObjectName("comboBox_taskPrio");
        comboBox_taskPrio->setGeometry(QRect(360, 30, 62, 22));
        label_taskLoc = new QLabel(create_task_window);
        label_taskLoc->setObjectName("label_taskLoc");
        label_taskLoc->setGeometry(QRect(30, 110, 40, 20));
        label_taskName = new QLabel(create_task_window);
        label_taskName->setObjectName("label_taskName");
        label_taskName->setGeometry(QRect(30, 30, 40, 20));
        lineEdit_taskName = new QLineEdit(create_task_window);
        lineEdit_taskName->setObjectName("lineEdit_taskName");
        lineEdit_taskName->setGeometry(QRect(80, 30, 113, 20));
        label_taskPrio = new QLabel(create_task_window);
        label_taskPrio->setObjectName("label_taskPrio");
        label_taskPrio->setGeometry(QRect(310, 30, 40, 20));
        textEdit_taskNote = new QTextEdit(create_task_window);
        textEdit_taskNote->setObjectName("textEdit_taskNote");
        textEdit_taskNote->setGeometry(QRect(80, 190, 194, 60));
        label_edTime = new QLabel(create_task_window);
        label_edTime->setObjectName("label_edTime");
        label_edTime->setGeometry(QRect(310, 70, 40, 20));
        pushButton_createTask = new QPushButton(create_task_window);
        pushButton_createTask->setObjectName("pushButton_createTask");
        pushButton_createTask->setGeometry(QRect(140, 320, 70, 20));
        warning_rmTimeTooEarly = new QLabel(create_task_window);
        warning_rmTimeTooEarly->setObjectName("warning_rmTimeTooEarly");
        warning_rmTimeTooEarly->setGeometry(QRect(80, 170, 130, 14));
        warning_rmTimeTooEarly->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 0, 0);"));
        lineEdit_taskLoc = new QLineEdit(create_task_window);
        lineEdit_taskLoc->setObjectName("lineEdit_taskLoc");
        lineEdit_taskLoc->setGeometry(QRect(80, 110, 113, 20));
        label_taskNote = new QLabel(create_task_window);
        label_taskNote->setObjectName("label_taskNote");
        label_taskNote->setGeometry(QRect(30, 190, 40, 20));
        label_rmTime_m = new QLabel(create_task_window);
        label_rmTime_m->setObjectName("label_rmTime_m");
        label_rmTime_m->setGeometry(QRect(170, 150, 45, 20));
        comboBox_taskCtg = new QComboBox(create_task_window);
        comboBox_taskCtg->addItem(QString());
        comboBox_taskCtg->addItem(QString());
        comboBox_taskCtg->addItem(QString());
        comboBox_taskCtg->addItem(QString());
        comboBox_taskCtg->addItem(QString());
        comboBox_taskCtg->addItem(QString());
        comboBox_taskCtg->setObjectName("comboBox_taskCtg");
        comboBox_taskCtg->setGeometry(QRect(360, 110, 62, 22));
        warning_taskNameEmpty = new QLabel(create_task_window);
        warning_taskNameEmpty->setObjectName("warning_taskNameEmpty");
        warning_taskNameEmpty->setGeometry(QRect(80, 50, 113, 14));
        warning_taskNameEmpty->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 0, 0);"));
        lineEdit_rmTime_m = new QLineEdit(create_task_window);
        lineEdit_rmTime_m->setObjectName("lineEdit_rmTime_m");
        lineEdit_rmTime_m->setGeometry(QRect(140, 150, 30, 20));
        label_taskCtg = new QLabel(create_task_window);
        label_taskCtg->setObjectName("label_taskCtg");
        label_taskCtg->setGeometry(QRect(310, 110, 40, 20));
        dateTimeEdit_stTime = new QDateTimeEdit(create_task_window);
        dateTimeEdit_stTime->setObjectName("dateTimeEdit_stTime");
        dateTimeEdit_stTime->setGeometry(QRect(80, 70, 194, 20));
        label_stTime = new QLabel(create_task_window);
        label_stTime->setObjectName("label_stTime");
        label_stTime->setGeometry(QRect(30, 70, 40, 20));
        dateTimeEdit_edTime = new QDateTimeEdit(create_task_window);
        dateTimeEdit_edTime->setObjectName("dateTimeEdit_edTime");
        dateTimeEdit_edTime->setGeometry(QRect(360, 70, 194, 20));
        label_rmTime = new QLabel(create_task_window);
        label_rmTime->setObjectName("label_rmTime");
        label_rmTime->setGeometry(QRect(30, 150, 40, 20));
        lineEdit_rmTime_h = new QLineEdit(create_task_window);
        lineEdit_rmTime_h->setObjectName("lineEdit_rmTime_h");
        lineEdit_rmTime_h->setGeometry(QRect(80, 150, 30, 20));
        pushButton_cancel = new QPushButton(create_task_window);
        pushButton_cancel->setObjectName("pushButton_cancel");
        pushButton_cancel->setGeometry(QRect(390, 320, 70, 20));
        warning_edTimeTooEarly = new QLabel(create_task_window);
        warning_edTimeTooEarly->setObjectName("warning_edTimeTooEarly");
        warning_edTimeTooEarly->setGeometry(QRect(360, 88, 194, 14));
        warning_edTimeTooEarly->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 0, 0);"));

        retranslateUi(create_task_window);

        QMetaObject::connectSlotsByName(create_task_window);
    } // setupUi

    void retranslateUi(QWidget *create_task_window)
    {
        create_task_window->setWindowTitle(QCoreApplication::translate("create_task_window", "Form", nullptr));
        label_rmTime_h->setText(QCoreApplication::translate("create_task_window", "<html><head/><body><p align=\"center\">\345\260\217\346\227\266</p></body></html>", nullptr));
        comboBox_taskPrio->setItemText(0, QCoreApplication::translate("create_task_window", "\344\275\216", nullptr));
        comboBox_taskPrio->setItemText(1, QCoreApplication::translate("create_task_window", "\344\270\255", nullptr));
        comboBox_taskPrio->setItemText(2, QCoreApplication::translate("create_task_window", "\351\253\230", nullptr));

        label_taskLoc->setText(QCoreApplication::translate("create_task_window", "<html><head/><body><p align=\"right\">\345\234\260\347\202\271</p></body></html>", nullptr));
        label_taskName->setText(QCoreApplication::translate("create_task_window", "<html><head/><body><p align=\"right\">\344\273\273\345\212\241\345\220\215\347\247\260</p></body></html>", nullptr));
        label_taskPrio->setText(QCoreApplication::translate("create_task_window", "<html><head/><body><p align=\"right\">\344\274\230\345\205\210\347\272\247</p></body></html>", nullptr));
        label_edTime->setText(QCoreApplication::translate("create_task_window", "<html><head/><body><p align=\"right\">\347\273\223\346\235\237\346\227\266\351\227\264</p></body></html>", nullptr));
        pushButton_createTask->setText(QCoreApplication::translate("create_task_window", "\345\210\233\345\273\272\344\273\273\345\212\241", nullptr));
        warning_rmTimeTooEarly->setText(QCoreApplication::translate("create_task_window", " \346\217\220\351\206\222\346\227\266\351\227\264\344\270\215\350\203\275\346\227\251\344\272\216\347\216\260\345\234\250\357\274\201", nullptr));
        lineEdit_taskLoc->setText(QString());
        label_taskNote->setText(QCoreApplication::translate("create_task_window", "<html><head/><body><p align=\"right\">\345\244\207\346\263\250</p></body></html>", nullptr));
        label_rmTime_m->setText(QCoreApplication::translate("create_task_window", "<html><head/><body><p align=\"center\">\345\210\206\351\222\237 \345\211\215</p></body></html>", nullptr));
        comboBox_taskCtg->setItemText(0, QCoreApplication::translate("create_task_window", "\345\255\246\344\271\240", nullptr));
        comboBox_taskCtg->setItemText(1, QCoreApplication::translate("create_task_window", "\345\250\261\344\271\220", nullptr));
        comboBox_taskCtg->setItemText(2, QCoreApplication::translate("create_task_window", "\347\224\237\346\264\273", nullptr));
        comboBox_taskCtg->setItemText(3, QCoreApplication::translate("create_task_window", "\345\267\245\344\275\234", nullptr));
        comboBox_taskCtg->setItemText(4, QCoreApplication::translate("create_task_window", "\350\277\220\345\212\250", nullptr));
        comboBox_taskCtg->setItemText(5, QCoreApplication::translate("create_task_window", "\345\205\266\344\273\226", nullptr));

        warning_taskNameEmpty->setText(QCoreApplication::translate("create_task_window", " \344\273\273\345\212\241\345\220\215\347\247\260\344\270\215\350\203\275\344\270\272\347\251\272\357\274\201", nullptr));
        label_taskCtg->setText(QCoreApplication::translate("create_task_window", "<html><head/><body><p align=\"right\">\345\210\206\347\261\273</p></body></html>", nullptr));
        label_stTime->setText(QCoreApplication::translate("create_task_window", "<html><head/><body><p align=\"right\">\345\274\200\345\247\213\346\227\266\351\227\264</p></body></html>", nullptr));
        label_rmTime->setText(QCoreApplication::translate("create_task_window", "<html><head/><body><p align=\"right\">\346\217\220\351\206\222\346\227\266\351\227\264</p></body></html>", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("create_task_window", "\345\217\226\346\266\210", nullptr));
        warning_edTimeTooEarly->setText(QCoreApplication::translate("create_task_window", " \347\273\223\346\235\237\346\227\266\351\227\264\344\270\215\350\203\275\346\227\251\344\272\216\345\274\200\345\247\213\346\227\266\351\227\264\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class create_task_window: public Ui_create_task_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_TASK_WINDOW_H
