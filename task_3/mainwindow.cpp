#include "mainwindow.h"
#include <QMessageBox>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->calculateButton, &QPushButton::clicked, this,
            &MainWindow::CalculateHelper);
    connect(ui->addButton, &QPushButton::clicked, this,
            &MainWindow::AddNumberHelper);
    connect(ui->clearButton, &QPushButton::clicked, this,
            &MainWindow::ClearHelper);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::VisualArray() {
    QString output = "";
    for (int i = 0; i < manager_.arr.size(); i++) {
        output += QString::number(manager_.arr[i]) + " ";
    }

    ui->arrayEdit->clear();
    ui->arrayEdit->setText(output);
}

void MainWindow::VisualResult(QVector<int> array) {
    QString output = "";
    for (int i = 0; i < array.size(); i++) {
        output += QString::number(array[i]) + " ";
    }

    ui->resultEdit->clear();
    ui->resultEdit->setText(output);
}

void MainWindow::AddNumberHelper() {
    QString input = ui->inputEdit->text();
    if (manager_.Valid(input)) {
        int number = input.toInt();
        manager_.AddNumber(number);
        VisualArray();
    } else {
        QMessageBox::warning(this, "Error of input",
                             "incorrect input, enter the number with int type",
                             QMessageBox::Ok);
    }
    ui->inputEdit->clear();
    ui->inputEdit->clear();
    ui->inputEdit->setFocus();
}

void MainWindow::CalculateHelper() {
    if (manager_.arr.size() > 0) {
        ui->resultEdit->clear();
        VisualResult(manager_.Calculate(manager_.arr));
    } else {
        QMessageBox::warning(this, "Error", "array is empty", QMessageBox::Ok);
    }
}

void MainWindow::ClearHelper() {
    manager_.Clear();
    ui->arrayEdit->clear();
    ui->resultEdit->clear();
}
