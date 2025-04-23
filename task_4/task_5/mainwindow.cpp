#include "mainwindow.h"
#include <QMessageBox>
//#include "test.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    /*test testing;
    testing.Testing();*/


    connect(ui->assignButton, &QPushButton::clicked, this,
            &MainWindow::AssignHelper);
    connect(ui->resizeButton, &QPushButton::clicked, this,
            &MainWindow::ResizeHelper);
    connect(ui->reserveButton, &QPushButton::clicked, this,
            &MainWindow::ReserveHelper);
    connect(ui->push_backButton, &QPushButton::clicked, this,
            &MainWindow::PushBackHelper);
    connect(ui->empalce_backButton, &QPushButton::clicked, this,
            &MainWindow::EmplaceBackHelper);
    connect(ui->emplaceButton, &QPushButton::clicked, this,
            &MainWindow::EmplaceHelper);
    connect(ui->sizeButton, &QPushButton::clicked, this,
            &MainWindow::SizeHelper);
    connect(ui->pop_backButton, &QPushButton::clicked, this,
            &MainWindow::PopBackHelper);
    connect(ui->atButton, &QPushButton::clicked, this, &MainWindow::AtHelper);
    connect(ui->eraseButton, &QPushButton::clicked, this,
            &MainWindow::EraseHelper);
    connect(ui->insertButton, &QPushButton::clicked, this,
            &MainWindow::InsertHelper);
    connect(ui->clearButton, &QPushButton::clicked, this,
            &MainWindow::ClearHelper);
    connect(ui->capacityButton, &QPushButton::clicked, this,
            &MainWindow::CapacityHelper);
    connect(ui->max_sizeButton, &QPushButton::clicked, this,
            &MainWindow::MaxSizeHelper);
}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::CheckInt(QString input) {
    bool ok;
    input.toInt(&ok);
    return ok;
}

void MainWindow::Error() {
    QMessageBox::warning(this, "error",
                         "Некорректный ввод. Пожалуйста, введите целое число.",
                         QMessageBox::Ok);
}

void MainWindow::VisualVector() {
    ui->vectorEdit->clear();
    QString out_put = "";
    for (size_t i = 0; i < vector_.size(); i++) {
        out_put += QString::number(vector_[i]) + " ";
    }

    ui->vectorEdit->setText(out_put);
}

void MainWindow::ReserveHelper() {
    QString input = ui->valueEdit->text();
    ui->valueEdit->clear();
    if (!CheckInt(input)) {
        Error();
        return;
    }

    try {
        int n = input.toInt();
        vector_.reserve(n);
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "error", QString("Error: ") + e.what());
    }
}

void MainWindow::ResizeHelper() {
    QString input = ui->valueEdit->text();
    ui->valueEdit->clear();
    QString input_2 = ui->forresizeEdit->text();
    ui->forresizeEdit->clear();
    if (!CheckInt(input) || !CheckInt(input_2)) {
        Error();
        return;
    }

    try {
        int value = input.toInt();
        int size = input_2.toInt();
        vector_.resize(size, value);
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "error", QString("Error: ") + e.what());
    }
    VisualVector();
}

void MainWindow::AssignHelper() {
    QString input = ui->valueEdit->text();
    ui->valueEdit->clear();
    QString input_2 = ui->forresizeEdit->text();
    ui->forresizeEdit->clear();
    if (!CheckInt(input) || !CheckInt(input_2)) {
        Error();
        return;
    }

    try {
        int value = input.toInt();
        int size = input_2.toInt();
        vector_.assign(size, value);
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "error", QString("Error: ") + e.what());
    }
    VisualVector();
}

void MainWindow::PushBackHelper() {
    QString input = ui->valueEdit->text();
    ui->valueEdit->clear();
    if (!CheckInt(input)) {
        Error();
        return;
    }

    try {
        int value = input.toInt();
        vector_.push_back(value);
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "error", QString("Error: ") + e.what());
    }
    VisualVector();
}

void MainWindow::EmplaceBackHelper() {
    QString input = ui->valueEdit->text();
    ui->valueEdit->clear();
    if (!CheckInt(input)) {
        Error();
        return;
    }

    try {
        int value = input.toInt();
        vector_.emplace_back(value);
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "error", QString("Error: ") + e.what());
    }
    VisualVector();
}

void MainWindow::EmplaceHelper() {
    QString input = ui->valueEdit->text();
    ui->valueEdit->clear();
    QString input_2 = ui->indexEdit->text();
    ui->indexEdit->clear();
    if (!CheckInt(input) || !CheckInt(input_2)) {
        Error();
        return;
    }

    try {
        int value = input.toInt();
        int index = input_2.toInt();
        vector_.emplace(vector_.begin() + index, value);
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "error", QString("Error: ") + e.what());
    }
    VisualVector();
}

void MainWindow::SizeHelper() {
    ui->resultEdit->clear();
    ui->resultEdit->setText(QString::number(vector_.size()));
}

void MainWindow::PopBackHelper() {
    try {
        vector_.pop_back();
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "error", QString("Error: ") + e.what());
    }
    VisualVector();
}

void MainWindow::AtHelper() {
    QString input = ui->indexEdit->text();
    ui->indexEdit->clear();
    if (!CheckInt(input)) {
        Error();
        return;
    }

    try {
        int index = input.toInt();
        ui->resultEdit->clear();
        ui->resultEdit->setText(QString::number(vector_.at(index)));
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "error", QString("Error: ") + e.what());
    }
    VisualVector();
}

void MainWindow::EraseHelper() {
    QString input = ui->indexEdit->text();
    ui->indexEdit->clear();
    if (!CheckInt(input)) {
        Error();
        return;
    }

    try {
        int index = input.toInt();
        vector_.erase(vector_.begin() + index);
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "error", QString("Error: ") + e.what());
    }
    VisualVector();
}

void MainWindow::InsertHelper() {
    QString input = ui->valueEdit->text();
    ui->valueEdit->clear();
    QString input_2 = ui->indexEdit->text();
    ui->indexEdit->clear();
    if (!CheckInt(input) || !CheckInt(input_2)) {
        Error();
        return;
    }

    try {
        int value = input.toInt();
        int index = input_2.toInt();
        vector_.insert(vector_.begin() + index, value);
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "error", QString("Error: ") + e.what());
    }
    VisualVector();
}

void MainWindow::ClearHelper() {
    vector_.clear();
    VisualVector();
}

void MainWindow::CapacityHelper() {
    ui->resultEdit->clear();
    ui->resultEdit->setText(QString::number(vector_.capacity()));
}

void MainWindow::MaxSizeHelper() {
    ui->resultEdit->clear();
    ui->resultEdit->setText(QString::number(vector_.max_size()));
}
