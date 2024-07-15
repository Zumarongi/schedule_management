/********************************************************************************
** Form generated from reading UI file 'time_conflict_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIME_CONFLICT_DIALOG_H
#define UI_TIME_CONFLICT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_time_conflict_dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *time_conflict_dialog)
    {
        if (time_conflict_dialog->objectName().isEmpty())
            time_conflict_dialog->setObjectName("time_conflict_dialog");
        time_conflict_dialog->resize(200, 120);
        buttonBox = new QDialogButtonBox(time_conflict_dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(0, 80, 200, 30));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(true);
        label = new QLabel(time_conflict_dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 30, 120, 36));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);

        retranslateUi(time_conflict_dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, time_conflict_dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, time_conflict_dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(time_conflict_dialog);
    } // setupUi

    void retranslateUi(QDialog *time_conflict_dialog)
    {
        time_conflict_dialog->setWindowTitle(QCoreApplication::translate("time_conflict_dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("time_conflict_dialog", "<html><head/><body><p align=\"center\">\350\257\245\344\273\273\345\212\241\344\270\216\345\205\266\344\273\226\344\273\273\345\212\241\346\227\266\351\227\264\345\206\262\347\252\201\357\274\214</p><p align=\"center\">\346\230\257\345\220\246\344\277\235\345\255\230\357\274\237</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class time_conflict_dialog: public Ui_time_conflict_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIME_CONFLICT_DIALOG_H
