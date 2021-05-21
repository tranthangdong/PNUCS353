/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label_TempNumber;
    QLabel *label_Do;
    QPushButton *pushButtoneTempCong;
    QPushButton *pushButton_TempTru;
    QPushButton *pushButton_Power;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(362, 604);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 10, 321, 161));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(30,144,255);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_TempNumber = new QLabel(frame);
        label_TempNumber->setObjectName(QString::fromUtf8("label_TempNumber"));
        label_TempNumber->setGeometry(QRect(160, 60, 111, 91));
        QFont font;
        font.setPointSize(72);
        label_TempNumber->setFont(font);
        label_TempNumber->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_Do = new QLabel(frame);
        label_Do->setObjectName(QString::fromUtf8("label_Do"));
        label_Do->setGeometry(QRect(270, 60, 31, 31));
        QFont font1;
        font1.setPointSize(16);
        label_Do->setFont(font1);
        label_Do->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButtoneTempCong = new QPushButton(centralwidget);
        pushButtoneTempCong->setObjectName(QString::fromUtf8("pushButtoneTempCong"));
        pushButtoneTempCong->setGeometry(QRect(270, 220, 75, 61));
        pushButton_TempTru = new QPushButton(centralwidget);
        pushButton_TempTru->setObjectName(QString::fromUtf8("pushButton_TempTru"));
        pushButton_TempTru->setGeometry(QRect(270, 290, 75, 61));
        pushButton_Power = new QPushButton(centralwidget);
        pushButton_Power->setObjectName(QString::fromUtf8("pushButton_Power"));
        pushButton_Power->setGeometry(QRect(20, 220, 75, 61));
        pushButton_Power->setAutoFillBackground(false);
        pushButton_Power->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 170, 0);\n"
"color: rgb(0, 170, 0);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 362, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_TempNumber->setText(QCoreApplication::translate("MainWindow", "25", nullptr));
        label_Do->setText(QCoreApplication::translate("MainWindow", "O", nullptr));
        pushButtoneTempCong->setText(QCoreApplication::translate("MainWindow", "TEMP +", nullptr));
        pushButton_TempTru->setText(QCoreApplication::translate("MainWindow", "TEMP -", nullptr));
        pushButton_Power->setText(QCoreApplication::translate("MainWindow", "POWER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
