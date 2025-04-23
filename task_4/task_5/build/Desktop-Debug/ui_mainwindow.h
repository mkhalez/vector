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
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *reserveButton;
    QPushButton *resizeButton;
    QPushButton *assignButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *push_backButton;
    QPushButton *empalce_backButton;
    QPushButton *emplaceButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *sizeButton;
    QPushButton *pop_backButton;
    QPushButton *atButton;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *eraseButton;
    QPushButton *capacityButton;
    QPushButton *insertButton;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *clearButton;
    QPushButton *max_sizeButton;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLineEdit *resultEdit;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QLineEdit *vectorEdit;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_2;
    QLineEdit *indexEdit;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_3;
    QLineEdit *valueEdit;
    QWidget *widget5;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_6;
    QLineEdit *forresizeEdit;
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
        widget->setGeometry(QRect(270, 40, 280, 166));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        reserveButton = new QPushButton(widget);
        reserveButton->setObjectName("reserveButton");

        horizontalLayout->addWidget(reserveButton);

        resizeButton = new QPushButton(widget);
        resizeButton->setObjectName("resizeButton");

        horizontalLayout->addWidget(resizeButton);

        assignButton = new QPushButton(widget);
        assignButton->setObjectName("assignButton");

        horizontalLayout->addWidget(assignButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        push_backButton = new QPushButton(widget);
        push_backButton->setObjectName("push_backButton");

        horizontalLayout_2->addWidget(push_backButton);

        empalce_backButton = new QPushButton(widget);
        empalce_backButton->setObjectName("empalce_backButton");

        horizontalLayout_2->addWidget(empalce_backButton);

        emplaceButton = new QPushButton(widget);
        emplaceButton->setObjectName("emplaceButton");

        horizontalLayout_2->addWidget(emplaceButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        sizeButton = new QPushButton(widget);
        sizeButton->setObjectName("sizeButton");

        horizontalLayout_3->addWidget(sizeButton);

        pop_backButton = new QPushButton(widget);
        pop_backButton->setObjectName("pop_backButton");

        horizontalLayout_3->addWidget(pop_backButton);

        atButton = new QPushButton(widget);
        atButton->setObjectName("atButton");

        horizontalLayout_3->addWidget(atButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        eraseButton = new QPushButton(widget);
        eraseButton->setObjectName("eraseButton");

        horizontalLayout_5->addWidget(eraseButton);

        capacityButton = new QPushButton(widget);
        capacityButton->setObjectName("capacityButton");

        horizontalLayout_5->addWidget(capacityButton);

        insertButton = new QPushButton(widget);
        insertButton->setObjectName("insertButton");

        horizontalLayout_5->addWidget(insertButton);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        clearButton = new QPushButton(widget);
        clearButton->setObjectName("clearButton");

        horizontalLayout_4->addWidget(clearButton);

        max_sizeButton = new QPushButton(widget);
        max_sizeButton->setObjectName("max_sizeButton");

        horizontalLayout_4->addWidget(max_sizeButton);


        verticalLayout->addLayout(horizontalLayout_4);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(20, 180, 193, 28));
        horizontalLayout_7 = new QHBoxLayout(widget1);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget1);
        label_4->setObjectName("label_4");

        horizontalLayout_7->addWidget(label_4);

        resultEdit = new QLineEdit(widget1);
        resultEdit->setObjectName("resultEdit");
        resultEdit->setReadOnly(true);

        horizontalLayout_7->addWidget(resultEdit);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(20, 20, 197, 28));
        horizontalLayout_8 = new QHBoxLayout(widget2);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget2);
        label->setObjectName("label");

        horizontalLayout_8->addWidget(label);

        vectorEdit = new QLineEdit(widget2);
        vectorEdit->setObjectName("vectorEdit");
        vectorEdit->setReadOnly(true);

        horizontalLayout_8->addWidget(vectorEdit);

        widget3 = new QWidget(centralwidget);
        widget3->setObjectName("widget3");
        widget3->setGeometry(QRect(20, 80, 187, 28));
        horizontalLayout_9 = new QHBoxLayout(widget3);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget3);
        label_2->setObjectName("label_2");

        horizontalLayout_9->addWidget(label_2);

        indexEdit = new QLineEdit(widget3);
        indexEdit->setObjectName("indexEdit");

        horizontalLayout_9->addWidget(indexEdit);

        widget4 = new QWidget(centralwidget);
        widget4->setObjectName("widget4");
        widget4->setGeometry(QRect(20, 130, 190, 28));
        horizontalLayout_10 = new QHBoxLayout(widget4);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget4);
        label_3->setObjectName("label_3");

        horizontalLayout_10->addWidget(label_3);

        valueEdit = new QLineEdit(widget4);
        valueEdit->setObjectName("valueEdit");

        horizontalLayout_10->addWidget(valueEdit);

        widget5 = new QWidget(centralwidget);
        widget5->setObjectName("widget5");
        widget5->setGeometry(QRect(20, 220, 161, 28));
        horizontalLayout_11 = new QHBoxLayout(widget5);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget5);
        label_6->setObjectName("label_6");

        horizontalLayout_11->addWidget(label_6);

        forresizeEdit = new QLineEdit(widget5);
        forresizeEdit->setObjectName("forresizeEdit");

        horizontalLayout_11->addWidget(forresizeEdit);

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
        reserveButton->setText(QCoreApplication::translate("MainWindow", "reserve", nullptr));
        resizeButton->setText(QCoreApplication::translate("MainWindow", "resize", nullptr));
        assignButton->setText(QCoreApplication::translate("MainWindow", "assign", nullptr));
        push_backButton->setText(QCoreApplication::translate("MainWindow", "push_back", nullptr));
        empalce_backButton->setText(QCoreApplication::translate("MainWindow", "emplace_back", nullptr));
        emplaceButton->setText(QCoreApplication::translate("MainWindow", "emplace", nullptr));
        sizeButton->setText(QCoreApplication::translate("MainWindow", "size", nullptr));
        pop_backButton->setText(QCoreApplication::translate("MainWindow", "pop_back", nullptr));
        atButton->setText(QCoreApplication::translate("MainWindow", "at", nullptr));
        eraseButton->setText(QCoreApplication::translate("MainWindow", "erase", nullptr));
        capacityButton->setText(QCoreApplication::translate("MainWindow", "capascity", nullptr));
        insertButton->setText(QCoreApplication::translate("MainWindow", "insert", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        max_sizeButton->setText(QCoreApplication::translate("MainWindow", "max_size", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "result:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "vector:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "index:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "value:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "additional size:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
