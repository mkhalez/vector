#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <chrono>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    manager_.size = 0;
    manager_.list_of_number = new int[manager_.size];

    ui->comboBox->addItem("Heap sort");
    ui->comboBox->addItem("Quick sort");
    ui->comboBox->addItem("Merge sort");

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::AddNumber);
    connect(ui->sortButton, &QPushButton::clicked, this,
            &MainWindow::SortHelper);
    connect(ui->findButton, &QPushButton::clicked, this,
            &MainWindow::FindHelper);
    connect(ui->clearButton, &QPushButton::clicked, this,
            &MainWindow::ClearHelper);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::VisualArray() {
    ui->arrayEdit->clear();
    QString output = "";


    for (int i = 0; i < manager_.size; i++) {
        output += QString::number(manager_.list_of_number[i]) + " ";
    }
    ui->arrayEdit->setText(output);
}

void MainWindow::AddNumber() {
    QString input = ui->inputEdit->text();
    if (manager_.Valid(input)) {
        manager_.list_of_number =
            manager_.AddElement(manager_.list_of_number, manager_.size);
        manager_.list_of_number[manager_.size - 1] = input.toInt();

        ui->inputEdit->clear();
        ui->inputEdit->setFocus();
        VisualArray();
    } else {
        QMessageBox::warning(this, "Error of input",
                             "incorrect input, enter the number with int type",
                             QMessageBox::Ok);

        ui->inputEdit->clear();
        ui->inputEdit->setFocus();
    }
}

void MainWindow::SortHelper() {
    if (manager_.size > 0) {
        ui->speedEdit->clear();
        int type_of_sort = ui->comboBox->currentIndex();
        auto start_time = std::chrono::steady_clock::now();
        switch (type_of_sort) {
            case 0:
                manager_.HeapSort(manager_.list_of_number, manager_.size - 1);
                break;
            case 1:
                manager_.QuickSort(manager_.list_of_number, 0,
                                   manager_.size - 1);
                break;
            case 2:
                manager_.MergeSort(manager_.list_of_number, 0,
                                   manager_.size - 1);
                break;
        }
        auto end_time = std::chrono::steady_clock::now();
        auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(
            end_time - start_time);
        ui->speedEdit->setText(QString::number(elapsed_ns.count()));
        VisualArray();
    } else {
        QMessageBox::warning(this, "Error", "array is empty", QMessageBox::Ok);
    }
}

void MainWindow::FindHelper() {
    ui->resulEdit->clear();
    QString input = ui->inputFind->text();
    if (manager_.Valid(input)) {
        int our_number = input.toInt();
        manager_.QuickSort(manager_.list_of_number, 0, manager_.size - 1);
        VisualArray();
        int index = manager_.BinarySearch(manager_.list_of_number, 0,
                                          manager_.size - 1, our_number);
        ui->resulEdit->setText(QString::number(index));
    } else {
        QMessageBox::warning(this, "Error of input",
                             "incorrect input, enter the number with int type",
                             QMessageBox::Ok);

        ui->inputFind->clear();
        ui->inputFind->setFocus();
    }
}

void MainWindow::ClearHelper() {
    manager_.ClearArray(manager_.list_of_number, manager_.size);
    ui->arrayEdit->clear();
}
