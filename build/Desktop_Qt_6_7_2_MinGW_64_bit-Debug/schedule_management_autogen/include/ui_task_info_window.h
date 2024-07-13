/********************************************************************************
** Form generated from reading UI file 'task_info_window.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_INFO_WINDOW_H
#define UI_TASK_INFO_WINDOW_H

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

class Ui_task_info_window
{
public:
    QLabel *label_taskName;
    QLabel *label_stTime;
    QLabel *label_taskLoc;
    QLineEdit *lineEdit_taskName;
    QPushButton *editButton_taskName;
    QDateTimeEdit *dateTimeEdit_stTime;
    QLineEdit *lineEdit_taskLoc;
    QPushButton *editButton_taskLoc;
    QLabel *label_taskPrio;
    QLabel *label_edTime;
    QDateTimeEdit *dateTimeEdit_edTime;
    QLabel *label_taskCtg;
    QLabel *label_rmTime;
    QLineEdit *lineEdit_rmTime_h;
    QLineEdit *lineEdit_rmTime_m;
    QLabel *label_rmTime_h;
    QLabel *label_rmTime_m;
    QPushButton *editButton_rmTime;
    QLabel *label_taskNote;
    QTextEdit *textEdit_taskNote;
    QPushButton *editButton_taskNote;
    QComboBox *comboBox_taskPrio;
    QComboBox *comboBox_taskCtg;
    QPushButton *pushButton_saveChanges;
    QPushButton *pushButton_deleteTask;
    QPushButton *pushButton_return;
    QPushButton *editButton_stTime;
    QPushButton *editButton_edTime;
    QPushButton *editButton_taskCtg;
    QPushButton *editButton_taskPrio;

    void setupUi(QWidget *task_info_window)
    {
        if (task_info_window->objectName().isEmpty())
            task_info_window->setObjectName("task_info_window");
        task_info_window->resize(600, 400);
        label_taskName = new QLabel(task_info_window);
        label_taskName->setObjectName("label_taskName");
        label_taskName->setGeometry(QRect(30, 60, 40, 20));
        label_stTime = new QLabel(task_info_window);
        label_stTime->setObjectName("label_stTime");
        label_stTime->setGeometry(QRect(30, 90, 40, 20));
        label_taskLoc = new QLabel(task_info_window);
        label_taskLoc->setObjectName("label_taskLoc");
        label_taskLoc->setGeometry(QRect(30, 120, 40, 20));
        lineEdit_taskName = new QLineEdit(task_info_window);
        lineEdit_taskName->setObjectName("lineEdit_taskName");
        lineEdit_taskName->setGeometry(QRect(80, 60, 113, 20));
        editButton_taskName = new QPushButton(task_info_window);
        editButton_taskName->setObjectName("editButton_taskName");
        editButton_taskName->setGeometry(QRect(200, 60, 22, 20));
        dateTimeEdit_stTime = new QDateTimeEdit(task_info_window);
        dateTimeEdit_stTime->setObjectName("dateTimeEdit_stTime");
        dateTimeEdit_stTime->setGeometry(QRect(80, 90, 194, 20));
        lineEdit_taskLoc = new QLineEdit(task_info_window);
        lineEdit_taskLoc->setObjectName("lineEdit_taskLoc");
        lineEdit_taskLoc->setGeometry(QRect(80, 120, 113, 20));
        editButton_taskLoc = new QPushButton(task_info_window);
        editButton_taskLoc->setObjectName("editButton_taskLoc");
        editButton_taskLoc->setGeometry(QRect(200, 120, 22, 20));
        label_taskPrio = new QLabel(task_info_window);
        label_taskPrio->setObjectName("label_taskPrio");
        label_taskPrio->setGeometry(QRect(310, 60, 40, 20));
        label_edTime = new QLabel(task_info_window);
        label_edTime->setObjectName("label_edTime");
        label_edTime->setGeometry(QRect(310, 90, 40, 20));
        dateTimeEdit_edTime = new QDateTimeEdit(task_info_window);
        dateTimeEdit_edTime->setObjectName("dateTimeEdit_edTime");
        dateTimeEdit_edTime->setGeometry(QRect(360, 90, 194, 20));
        label_taskCtg = new QLabel(task_info_window);
        label_taskCtg->setObjectName("label_taskCtg");
        label_taskCtg->setGeometry(QRect(310, 120, 40, 20));
        label_rmTime = new QLabel(task_info_window);
        label_rmTime->setObjectName("label_rmTime");
        label_rmTime->setGeometry(QRect(30, 150, 40, 20));
        lineEdit_rmTime_h = new QLineEdit(task_info_window);
        lineEdit_rmTime_h->setObjectName("lineEdit_rmTime_h");
        lineEdit_rmTime_h->setGeometry(QRect(80, 150, 30, 20));
        lineEdit_rmTime_m = new QLineEdit(task_info_window);
        lineEdit_rmTime_m->setObjectName("lineEdit_rmTime_m");
        lineEdit_rmTime_m->setGeometry(QRect(140, 150, 30, 20));
        label_rmTime_h = new QLabel(task_info_window);
        label_rmTime_h->setObjectName("label_rmTime_h");
        label_rmTime_h->setGeometry(QRect(110, 150, 30, 20));
        label_rmTime_m = new QLabel(task_info_window);
        label_rmTime_m->setObjectName("label_rmTime_m");
        label_rmTime_m->setGeometry(QRect(170, 150, 45, 20));
        editButton_rmTime = new QPushButton(task_info_window);
        editButton_rmTime->setObjectName("editButton_rmTime");
        editButton_rmTime->setGeometry(QRect(215, 150, 22, 20));
        label_taskNote = new QLabel(task_info_window);
        label_taskNote->setObjectName("label_taskNote");
        label_taskNote->setGeometry(QRect(30, 180, 40, 20));
        textEdit_taskNote = new QTextEdit(task_info_window);
        textEdit_taskNote->setObjectName("textEdit_taskNote");
        textEdit_taskNote->setGeometry(QRect(80, 180, 194, 60));
        editButton_taskNote = new QPushButton(task_info_window);
        editButton_taskNote->setObjectName("editButton_taskNote");
        editButton_taskNote->setGeometry(QRect(280, 220, 22, 20));
        comboBox_taskPrio = new QComboBox(task_info_window);
        comboBox_taskPrio->addItem(QString());
        comboBox_taskPrio->addItem(QString());
        comboBox_taskPrio->addItem(QString());
        comboBox_taskPrio->setObjectName("comboBox_taskPrio");
        comboBox_taskPrio->setGeometry(QRect(360, 60, 62, 22));
        comboBox_taskCtg = new QComboBox(task_info_window);
        comboBox_taskCtg->addItem(QString());
        comboBox_taskCtg->addItem(QString());
        comboBox_taskCtg->addItem(QString());
        comboBox_taskCtg->addItem(QString());
        comboBox_taskCtg->addItem(QString());
        comboBox_taskCtg->setObjectName("comboBox_taskCtg");
        comboBox_taskCtg->setGeometry(QRect(360, 120, 62, 22));
        pushButton_saveChanges = new QPushButton(task_info_window);
        pushButton_saveChanges->setObjectName("pushButton_saveChanges");
        pushButton_saveChanges->setGeometry(QRect(80, 320, 70, 20));
        pushButton_deleteTask = new QPushButton(task_info_window);
        pushButton_deleteTask->setObjectName("pushButton_deleteTask");
        pushButton_deleteTask->setGeometry(QRect(265, 320, 70, 20));
        pushButton_return = new QPushButton(task_info_window);
        pushButton_return->setObjectName("pushButton_return");
        pushButton_return->setGeometry(QRect(450, 320, 70, 20));
        editButton_stTime = new QPushButton(task_info_window);
        editButton_stTime->setObjectName("editButton_stTime");
        editButton_stTime->setGeometry(QRect(280, 90, 22, 20));
        editButton_edTime = new QPushButton(task_info_window);
        editButton_edTime->setObjectName("editButton_edTime");
        editButton_edTime->setGeometry(QRect(560, 90, 22, 20));
        editButton_taskCtg = new QPushButton(task_info_window);
        editButton_taskCtg->setObjectName("editButton_taskCtg");
        editButton_taskCtg->setGeometry(QRect(430, 120, 22, 20));
        editButton_taskPrio = new QPushButton(task_info_window);
        editButton_taskPrio->setObjectName("editButton_taskPrio");
        editButton_taskPrio->setGeometry(QRect(430, 60, 22, 20));

        retranslateUi(task_info_window);

        QMetaObject::connectSlotsByName(task_info_window);
    } // setupUi

    void retranslateUi(QWidget *task_info_window)
    {
        task_info_window->setWindowTitle(QCoreApplication::translate("task_info_window", "Form", nullptr));
        label_taskName->setText(QCoreApplication::translate("task_info_window", "<html><head/><body><p align=\"right\">\344\273\273\345\212\241\345\220\215\347\247\260</p></body></html>", nullptr));
        label_stTime->setText(QCoreApplication::translate("task_info_window", "<html><head/><body><p align=\"right\">\345\274\200\345\247\213\346\227\266\351\227\264</p></body></html>", nullptr));
        label_taskLoc->setText(QCoreApplication::translate("task_info_window", "<html><head/><body><p align=\"right\">\345\234\260\347\202\271</p></body></html>", nullptr));
        editButton_taskName->setText(QCoreApplication::translate("task_info_window", "Edit", nullptr));
        lineEdit_taskLoc->setText(QString());
        editButton_taskLoc->setText(QCoreApplication::translate("task_info_window", "Edit", nullptr));
        label_taskPrio->setText(QCoreApplication::translate("task_info_window", "<html><head/><body><p align=\"right\">\344\274\230\345\205\210\347\272\247</p></body></html>", nullptr));
        label_edTime->setText(QCoreApplication::translate("task_info_window", "<html><head/><body><p align=\"right\">\347\273\223\346\235\237\346\227\266\351\227\264</p></body></html>", nullptr));
        label_taskCtg->setText(QCoreApplication::translate("task_info_window", "<html><head/><body><p align=\"right\">\345\210\206\347\261\273</p></body></html>", nullptr));
        label_rmTime->setText(QCoreApplication::translate("task_info_window", "<html><head/><body><p align=\"right\">\346\217\220\351\206\222\346\227\266\351\227\264</p></body></html>", nullptr));
        label_rmTime_h->setText(QCoreApplication::translate("task_info_window", "<html><head/><body><p align=\"center\">\345\260\217\346\227\266</p></body></html>", nullptr));
        label_rmTime_m->setText(QCoreApplication::translate("task_info_window", "<html><head/><body><p align=\"center\">\345\210\206\351\222\237 \345\211\215</p></body></html>", nullptr));
        editButton_rmTime->setText(QCoreApplication::translate("task_info_window", "Edit", nullptr));
        label_taskNote->setText(QCoreApplication::translate("task_info_window", "<html><head/><body><p align=\"right\">\345\244\207\346\263\250</p></body></html>", nullptr));
        editButton_taskNote->setText(QCoreApplication::translate("task_info_window", "Edit", nullptr));
        comboBox_taskPrio->setItemText(0, QCoreApplication::translate("task_info_window", "\344\275\216", nullptr));
        comboBox_taskPrio->setItemText(1, QCoreApplication::translate("task_info_window", "\344\270\255", nullptr));
        comboBox_taskPrio->setItemText(2, QCoreApplication::translate("task_info_window", "\351\253\230", nullptr));

        comboBox_taskCtg->setItemText(0, QCoreApplication::translate("task_info_window", "\345\255\246\344\271\240", nullptr));
        comboBox_taskCtg->setItemText(1, QCoreApplication::translate("task_info_window", "\345\250\261\344\271\220", nullptr));
        comboBox_taskCtg->setItemText(2, QCoreApplication::translate("task_info_window", "\347\224\237\346\264\273", nullptr));
        comboBox_taskCtg->setItemText(3, QCoreApplication::translate("task_info_window", "\345\267\245\344\275\234", nullptr));
        comboBox_taskCtg->setItemText(4, QCoreApplication::translate("task_info_window", "\350\277\220\345\212\250", nullptr));

        pushButton_saveChanges->setText(QCoreApplication::translate("task_info_window", "\344\277\235\345\255\230\346\233\264\346\224\271", nullptr));
        pushButton_deleteTask->setText(QCoreApplication::translate("task_info_window", "\345\210\240\351\231\244\344\273\273\345\212\241", nullptr));
        pushButton_return->setText(QCoreApplication::translate("task_info_window", "\350\277\224\345\233\236", nullptr));
        editButton_stTime->setText(QCoreApplication::translate("task_info_window", "Edit", nullptr));
        editButton_edTime->setText(QCoreApplication::translate("task_info_window", "Edit", nullptr));
        editButton_taskCtg->setText(QCoreApplication::translate("task_info_window", "Edit", nullptr));
        editButton_taskPrio->setText(QCoreApplication::translate("task_info_window", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class task_info_window: public Ui_task_info_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_INFO_WINDOW_H
