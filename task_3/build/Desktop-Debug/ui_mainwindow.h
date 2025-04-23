/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *inputEdit;
    QPushButton *addButton;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *arrayEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *resultEdit;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *clearButton;
    QPushButton *calculateButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(330, 40, 276, 28));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        inputEdit = new QLineEdit(widget);
        inputEdit->setObjectName("inputEdit");

        horizontalLayout_3->addWidget(inputEdit);

        addButton = new QPushButton(widget);
        addButton->setObjectName("addButton");

        horizontalLayout_3->addWidget(addButton);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(80, 40, 195, 64));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(widget1);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        arrayEdit = new QLineEdit(widget1);
        arrayEdit->setObjectName("arrayEdit");
        arrayEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(arrayEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(widget1);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        resultEdit = new QLineEdit(widget1);
        resultEdit->setObjectName("resultEdit");
        resultEdit->setReadOnly(true);

        horizontalLayout->addWidget(resultEdit);


        verticalLayout->addLayout(horizontalLayout);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(330, 80, 168, 28));
        horizontalLayout_4 = new QHBoxLayout(widget2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        clearButton = new QPushButton(widget2);
        clearButton->setObjectName("clearButton");

        horizontalLayout_4->addWidget(clearButton);

        calculateButton = new QPushButton(widget2);
        calculateButton->setObjectName("calculateButton");

        horizontalLayout_4->addWidget(calculateButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "input:", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "array:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "result:", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        calculateButton->setText(QCoreApplication::translate("MainWindow", "calculate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
