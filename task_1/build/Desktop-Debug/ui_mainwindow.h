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
#include <QtWidgets/QComboBox>
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
    QPushButton *clearButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *inputEdit;
    QPushButton *addButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *arrayEdit;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *sortButton;
    QComboBox *comboBox;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *inputFind;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLineEdit *resulEdit;
    QPushButton *findButton;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLineEdit *speedEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(70, 210, 141, 61));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 20, 311, 66));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        inputEdit = new QLineEdit(widget);
        inputEdit->setObjectName("inputEdit");

        horizontalLayout->addWidget(inputEdit);

        addButton = new QPushButton(widget);
        addButton->setObjectName("addButton");

        horizontalLayout->addWidget(addButton);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout_3->addWidget(label);

        arrayEdit = new QLineEdit(widget);
        arrayEdit->setObjectName("arrayEdit");
        arrayEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(arrayEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(20, 120, 281, 28));
        horizontalLayout_4 = new QHBoxLayout(widget1);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        sortButton = new QPushButton(widget1);
        sortButton->setObjectName("sortButton");

        horizontalLayout_4->addWidget(sortButton);

        comboBox = new QComboBox(widget1);
        comboBox->setObjectName("comboBox");

        horizontalLayout_4->addWidget(comboBox);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(450, 40, 241, 98));
        verticalLayout_3 = new QVBoxLayout(widget2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_2 = new QLabel(widget2);
        label_2->setObjectName("label_2");

        horizontalLayout_5->addWidget(label_2);

        inputFind = new QLineEdit(widget2);
        inputFind->setObjectName("inputFind");

        horizontalLayout_5->addWidget(inputFind);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_3 = new QLabel(widget2);
        label_3->setObjectName("label_3");

        horizontalLayout_6->addWidget(label_3);

        resulEdit = new QLineEdit(widget2);
        resulEdit->setObjectName("resulEdit");
        resulEdit->setReadOnly(true);

        horizontalLayout_6->addWidget(resulEdit);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_3->addLayout(verticalLayout_2);

        findButton = new QPushButton(widget2);
        findButton->setObjectName("findButton");

        verticalLayout_3->addWidget(findButton);

        widget3 = new QWidget(centralwidget);
        widget3->setObjectName("widget3");
        widget3->setGeometry(QRect(280, 200, 216, 28));
        horizontalLayout_7 = new QHBoxLayout(widget3);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget3);
        label_4->setObjectName("label_4");

        horizontalLayout_7->addWidget(label_4);

        speedEdit = new QLineEdit(widget3);
        speedEdit->setObjectName("speedEdit");
        speedEdit->setReadOnly(true);

        horizontalLayout_7->addWidget(speedEdit);

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
        clearButton->setText(QCoreApplication::translate("MainWindow", "delete array", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "add number", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "array:", nullptr));
        sortButton->setText(QCoreApplication::translate("MainWindow", "sort", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "find number:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "index:", nullptr));
        findButton->setText(QCoreApplication::translate("MainWindow", "find", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "speed:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
