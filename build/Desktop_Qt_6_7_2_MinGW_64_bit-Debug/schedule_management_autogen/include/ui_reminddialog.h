/********************************************************************************
** Form generated from reading UI file 'reminddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMINDDIALOG_H
#define UI_REMINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_remindDialog
{
public:
    QPushButton *OK_button;
    QLabel *TaskName;
    QLabel *label;
    QLabel *TaskTime;
    QLabel *label_2;
    QPushButton *task_info_button;
    QLabel *label_3;
    QComboBox *comboBox;

    void setupUi(QDialog *remindDialog)
    {
        if (remindDialog->objectName().isEmpty())
            remindDialog->setObjectName("remindDialog");
        remindDialog->resize(400, 300);
        OK_button = new QPushButton(remindDialog);
        OK_button->setObjectName("OK_button");
        OK_button->setGeometry(QRect(130, 240, 80, 20));
        TaskName = new QLabel(remindDialog);
        TaskName->setObjectName("TaskName");
        TaskName->setGeometry(QRect(70, 70, 45, 13));
        label = new QLabel(remindDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 70, 45, 13));
        TaskTime = new QLabel(remindDialog);
        TaskTime->setObjectName("TaskTime");
        TaskTime->setGeometry(QRect(160, 70, 45, 13));
        label_2 = new QLabel(remindDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 70, 45, 13));
        task_info_button = new QPushButton(remindDialog);
        task_info_button->setObjectName("task_info_button");
        task_info_button->setGeometry(QRect(130, 100, 80, 20));
        label_3 = new QLabel(remindDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 130, 141, 20));
        comboBox = new QComboBox(remindDialog);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(70, 170, 181, 22));

        retranslateUi(remindDialog);

        QMetaObject::connectSlotsByName(remindDialog);
    } // setupUi

    void retranslateUi(QDialog *remindDialog)
    {
        remindDialog->setWindowTitle(QCoreApplication::translate("remindDialog", "Dialog", nullptr));
        OK_button->setText(QCoreApplication::translate("remindDialog", "\347\241\256\350\256\244", nullptr));
        TaskName->setText(QCoreApplication::translate("remindDialog", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("remindDialog", "\345\260\206\345\234\250", nullptr));
        TaskTime->setText(QCoreApplication::translate("remindDialog", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("remindDialog", "\345\220\216\345\274\200\345\247\213", nullptr));
        task_info_button->setText(QCoreApplication::translate("remindDialog", "\346\237\245\347\234\213\344\273\273\345\212\241\344\277\241\346\201\257", nullptr));
        label_3->setText(QCoreApplication::translate("remindDialog", "\346\230\257\345\220\246\345\206\215\346\254\241\346\217\220\351\206\222", nullptr));
    } // retranslateUi

};

namespace Ui {
    class remindDialog: public Ui_remindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMINDDIALOG_H
