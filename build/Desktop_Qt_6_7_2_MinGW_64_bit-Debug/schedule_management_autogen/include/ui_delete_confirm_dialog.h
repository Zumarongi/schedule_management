/********************************************************************************
** Form generated from reading UI file 'delete_confirm_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_CONFIRM_DIALOG_H
#define UI_DELETE_CONFIRM_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_delete_confirm_dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *delete_confirm_dialog)
    {
        if (delete_confirm_dialog->objectName().isEmpty())
            delete_confirm_dialog->setObjectName("delete_confirm_dialog");
        delete_confirm_dialog->resize(200, 120);
        buttonBox = new QDialogButtonBox(delete_confirm_dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(0, 80, 200, 30));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        label = new QLabel(delete_confirm_dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 40, 60, 12));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);

        retranslateUi(delete_confirm_dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, delete_confirm_dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, delete_confirm_dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(delete_confirm_dialog);
    } // setupUi

    void retranslateUi(QDialog *delete_confirm_dialog)
    {
        delete_confirm_dialog->setWindowTitle(QCoreApplication::translate("delete_confirm_dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("delete_confirm_dialog", "\347\241\256\350\256\244\345\210\240\351\231\244\344\273\273\345\212\241\357\274\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class delete_confirm_dialog: public Ui_delete_confirm_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_CONFIRM_DIALOG_H
