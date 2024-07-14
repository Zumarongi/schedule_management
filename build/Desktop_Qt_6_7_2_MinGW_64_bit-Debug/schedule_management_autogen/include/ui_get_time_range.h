/********************************************************************************
** Form generated from reading UI file 'get_time_range.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GET_TIME_RANGE_H
#define UI_GET_TIME_RANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_get_time_range
{
public:
    QDateTimeEdit *min_timeEdit;
    QDateTimeEdit *max_timeEdit;
    QPushButton *OK_button;
    QLabel *label;
    QLabel *label_2;
    QLabel *error_range_warning;

    void setupUi(QDialog *get_time_range)
    {
        if (get_time_range->objectName().isEmpty())
            get_time_range->setObjectName("get_time_range");
        get_time_range->resize(400, 300);
        min_timeEdit = new QDateTimeEdit(get_time_range);
        min_timeEdit->setObjectName("min_timeEdit");
        min_timeEdit->setGeometry(QRect(90, 90, 194, 22));
        max_timeEdit = new QDateTimeEdit(get_time_range);
        max_timeEdit->setObjectName("max_timeEdit");
        max_timeEdit->setGeometry(QRect(90, 130, 194, 22));
        OK_button = new QPushButton(get_time_range);
        OK_button->setObjectName("OK_button");
        OK_button->setGeometry(QRect(140, 200, 80, 20));
        label = new QLabel(get_time_range);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 90, 16, 20));
        label_2 = new QLabel(get_time_range);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 130, 16, 16));
        error_range_warning = new QLabel(get_time_range);
        error_range_warning->setObjectName("error_range_warning");
        error_range_warning->setGeometry(QRect(150, 160, 71, 20));
        error_range_warning->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(get_time_range);

        QMetaObject::connectSlotsByName(get_time_range);
    } // setupUi

    void retranslateUi(QDialog *get_time_range)
    {
        get_time_range->setWindowTitle(QCoreApplication::translate("get_time_range", "Dialog", nullptr));
        OK_button->setText(QCoreApplication::translate("get_time_range", "\347\241\256\350\256\244", nullptr));
        label->setText(QCoreApplication::translate("get_time_range", "\344\273\216", nullptr));
        label_2->setText(QCoreApplication::translate("get_time_range", "\345\210\260", nullptr));
        error_range_warning->setText(QCoreApplication::translate("get_time_range", "\346\227\266\351\227\264\350\214\203\345\233\264\351\224\231\350\257\257\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class get_time_range: public Ui_get_time_range {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GET_TIME_RANGE_H
