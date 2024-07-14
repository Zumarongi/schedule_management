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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_create_task_window
{
public:

    void setupUi(QWidget *create_task_window)
    {
        if (create_task_window->objectName().isEmpty())
            create_task_window->setObjectName("create_task_window");
        create_task_window->resize(320, 240);

        retranslateUi(create_task_window);

        QMetaObject::connectSlotsByName(create_task_window);
    } // setupUi

    void retranslateUi(QWidget *create_task_window)
    {
        create_task_window->setWindowTitle(QCoreApplication::translate("create_task_window", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class create_task_window: public Ui_create_task_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_TASK_WINDOW_H
