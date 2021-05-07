/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label_ThongBao;
    QSplitter *splitter;
    QPushButton *pButton_Exit;
    QPushButton *pButton_Hello;
    QLabel *label1;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->setEnabled(true);
        Dialog->resize(471, 373);
        Dialog->setMouseTracking(false);
        label_ThongBao = new QLabel(Dialog);
        label_ThongBao->setObjectName(QString::fromUtf8("label_ThongBao"));
        label_ThongBao->setGeometry(QRect(130, 250, 211, 31));
        splitter = new QSplitter(Dialog);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(150, 330, 150, 23));
        splitter->setOrientation(Qt::Horizontal);
        pButton_Exit = new QPushButton(splitter);
        pButton_Exit->setObjectName(QString::fromUtf8("pButton_Exit"));
        splitter->addWidget(pButton_Exit);
        pButton_Hello = new QPushButton(Dialog);
        pButton_Hello->setObjectName(QString::fromUtf8("pButton_Hello"));
        pButton_Hello->setGeometry(QRect(150, 290, 150, 23));
        label1 = new QLabel(Dialog);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(40, 30, 371, 201));
        label1->setScaledContents(false);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label_ThongBao->setText(QCoreApplication::translate("Dialog", "Xin ch\303\240o! T\303\264i t\303\252n l\303\240 Tr\341\272\247n L\303\252 Th\304\203ng \304\220\341\273\223ng", nullptr));
        pButton_Exit->setText(QCoreApplication::translate("Dialog", "Exit", nullptr));
        pButton_Hello->setText(QCoreApplication::translate("Dialog", "Hello", nullptr));
        label1->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
