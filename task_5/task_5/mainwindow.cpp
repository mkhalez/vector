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

    connect(ui->assignButton2, &QPushButton::clicked, this,
            &MainWindow::AssignHelper2);
    connect(ui->resizeButton2, &QPushButton::clicked, this,
            &MainWindow::ResizeHelper2);
    connect(ui->reserveButton2, &QPushButton::clicked, this,
            &MainWindow::ReserveHelper2);
    connect(ui->push_backButton2, &QPushButton::clicked, this,
            &MainWindow::PushBackHelper2);
    connect(ui->empalce_backButton2, &QPushButton::clicked, this,
            &MainWindow::EmplaceBackHelper2);
    connect(ui->emplaceButton2, &QPushButton::clicked, this,
            &MainWindow::EmplaceHelper2);
    connect(ui->sizeButton2, &QPushButton::clicked, this,
            &MainWindow::SizeHelper2);
    connect(ui->pop_backButton2, &QPushButton::clicked, this,
            &MainWindow::PopBackHelper2);
    connect(ui->atButton2, &QPushButton::clicked, this, &MainWindow::AtHelper2);
    connect(ui->eraseButton2, &QPushButton::clicked, this,
            &MainWindow::EraseHelper2);
    connect(ui->insertButton2, &QPushButton::clicked, this,
            &MainWindow::InsertHelper2);
    connect(ui->clearButton2, &QPushButton::clicked, this,
            &MainWindow::ClearHelper2);
    connect(ui->capacityButton2, &QPushButton::clicked, this,
            &MainWindow::CapacityHelper2);
    connect(ui->max_sizeButton2, &QPushButton::clicked, this,
            &MainWindow::MaxSizeHelper2);

    connect(ui->assignButton3, &QPushButton::clicked, this,
            &MainWindow::AssignHelper3);
    connect(ui->resizeButton3, &QPushButton::clicked, this,
            &MainWindow::ResizeHelper3);
    connect(ui->reserveButton3, &QPushButton::clicked, this,
            &MainWindow::ReserveHelper3);
    connect(ui->push_backButton3, &QPushButton::clicked, this,
            &MainWindow::PushBackHelper3);
    connect(ui->empalce_backButton3, &QPushButton::clicked, this,
            &MainWindow::EmplaceBackHelper3);
    connect(ui->emplaceButton3, &QPushButton::clicked, this,
            &MainWindow::EmplaceHelper3);
    connect(ui->sizeButton3, &QPushButton::clicked, this,
            &MainWindow::SizeHelper3);
    connect(ui->pop_backButton3, &QPushButton::clicked, this,
            &MainWindow::PopBackHelper3);
    connect(ui->atButton3, &QPushButton::clicked, this, &MainWindow::AtHelper3);
    connect(ui->eraseButton3, &QPushButton::clicked, this,
            &MainWindow::EraseHelper3);
    connect(ui->insertButton3, &QPushButton::clicked, this,
            &MainWindow::InsertHelper3);
    connect(ui->clearButton3, &QPushButton::clicked, this,
            &MainWindow::ClearHelper3);
    connect(ui->capacityButton3, &QPushButton::clicked, this,
            &MainWindow::CapacityHelper3);
    connect(ui->max_sizeButton3, &QPushButton::clicked, this,
            &MainWindow::MaxSizeHelper3);
}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::CheckInt(QString input) {
    bool ok;
    input.toInt(&ok);
    return ok;
}

bool MainWindow::CheckDouble(QString input) {
    bool ok;
    input.toDouble(&ok);
    return ok;
}

void MainWindow::Error() {
    QMessageBox::warning(this, "error",
                         "Некорректный ввод. Пожалуйста, введите целое число.",
                         QMessageBox::Ok);
}

void MainWindow::ErrorDouble() {
    QMessageBox::warning(
        this, "error", "Некорректный ввод. Пожалуйста, введите дробное число.",
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

void MainWindow::VisualVector2() {
    ui->vectorEdit2->clear();
    QString output = "";

    for (size_t i = 0; i < vector_2.size(); i++) {
        const Pair<int, double>& currentPair = vector_2[i];

        output += "(" + QString::number(currentPair.first) + ", " +
                  QString::number(currentPair.second, 'f', 2) + ") ";

        if ((i + 1) % 5 == 0) {
            output += "\n";
        }
    }

    ui->vectorEdit2->setText(output.trimmed());
}

void MainWindow::VisualVector3() {
    ui->vectorEdit3->clear();
    QString output = "";

    for (size_t i = 0; i < container_.size(); i++) {
        output += QString("[Элемент %1] ").arg(i);

        output += "[";


        for (const auto& num : container_[i].first) {
            output += QString::number(num) + " ";
        }
        output = output.trimmed() + "] | ";

        output += "[";


        for (const auto& pair : container_[i].second) {
            output +=
                QString("(%1,%2) ").arg(pair.first).arg(pair.second, 0, 'f', 2);
        }
        output = output.trimmed() + "]";

        output += "\n";
    }

    ui->vectorEdit3->setText(output.trimmed());
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

// -----------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------

void MainWindow::ReserveHelper2() {
    QString input = ui->valueEdit2->text();
    ui->valueEdit2->clear();
    if (!CheckInt(input)) {
        Error();
        return;
    }

    try {
        int n = input.toInt();
        vector_2.reserve(n);
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "error", QString("Error: ") + e.what());
    }
}

void MainWindow::ResizeHelper2() {
    QString input = ui->valueEdit2->text();
    ui->valueEdit->clear();
    QString input_2 = ui->forresizeEdit2->text();
    ui->forresizeEdit->clear();
    QString input_3 = ui->value2Edit2->text();
    if (!CheckInt(input) || !CheckInt(input_2)) {
        Error();
        return;
    }
    if (!CheckDouble(input_3)) {
        ErrorDouble();
        return;
    }

    try {
        int value = input.toInt();
        int size = input_2.toInt();
        int value_2 = input_3.toDouble();

        Pair<int, double> valuePair(value, value_2);

        vector_2.resize(size, valuePair);
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "error", QString("Error: ") + e.what());
    }
    VisualVector2();
}

void MainWindow::AssignHelper2() {
    QString inputInt = ui->valueEdit2->text();
    QString inputDouble = ui->value2Edit2->text();
    QString inputSize = ui->forresizeEdit2->text();

    ui->valueEdit->clear();
    ui->value2Edit2->clear();
    ui->forresizeEdit2->clear();

    if (!CheckInt(inputInt) || !CheckInt(inputSize)) {
        Error();
        return;
    }
    if (!CheckDouble(inputDouble)) {
        ErrorDouble();
        return;
    }

    try {
        int intValue = inputInt.toInt();
        double doubleValue = inputDouble.toDouble();
        int size = inputSize.toInt();
        if (size < 0) {
            throw std::invalid_argument("Размер не может быть отрицательным");
        }

        Pair<int, double> fillPair(intValue, doubleValue);

        vector_2.assign(size, fillPair);
    }

    catch (const std::invalid_argument& e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "Ошибка",
                              QString("Произошла ошибка: ") + e.what());
    }

    VisualVector2();
}

void MainWindow::PushBackHelper2() {
    QString inputInt = ui->valueEdit2->text();
    QString inputDouble = ui->value2Edit2->text();

    ui->valueEdit2->clear();
    ui->value2Edit2->clear();

    if (!CheckInt(inputInt)) {
        Error();
        return;
    }
    if (!CheckDouble(inputDouble)) {
        ErrorDouble();
        return;
    }

    try {
        int intValue = inputInt.toInt();
        double doubleValue = inputDouble.toDouble();

        Pair<int, double> newPair(intValue, doubleValue);
        vector_2.push_back(newPair);
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "error", QString("Error: ") + e.what());
    }

    VisualVector2();
}

void MainWindow::EmplaceBackHelper2() {
    QString inputInt = ui->valueEdit2->text();
    QString inputDouble = ui->value2Edit2->text();

    ui->valueEdit2->clear();
    ui->value2Edit2->clear();

    if (!CheckInt(inputInt)) {
        Error();
        return;
    }
    if (!CheckDouble(inputDouble)) {
        ErrorDouble();
        return;
    }

    try {
        int intValue = inputInt.toInt();
        double doubleValue = inputDouble.toDouble();

        vector_2.emplace_back(intValue, doubleValue);
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "error", QString("Error: ") + e.what());
    }

    VisualVector2();
}

void MainWindow::EmplaceHelper2() {
    QString inputInt = ui->valueEdit2->text();
    QString inputDouble = ui->value2Edit2->text();
    QString inputIndex = ui->indexEdit2->text();

    ui->valueEdit2->clear();
    ui->value2Edit2->clear();
    ui->indexEdit2->clear();

    if (!CheckInt(inputInt) || !CheckInt(inputIndex)) {
        Error();
        return;
    }
    if (!CheckDouble(inputDouble)) {
        ErrorDouble();
        return;
    }

    try {
        int intValue = inputInt.toInt();
        double doubleValue = inputDouble.toDouble();
        int index = inputIndex.toInt();

        if (index < 0 || index > static_cast<int>(vector_2.size())) {
            throw std::out_of_range("Invalid index");
        }

        vector_2.emplace(vector_2.begin() + index, intValue, doubleValue);
    }

    catch (const std::out_of_range& e) {
        QMessageBox::critical(this, "Ошибка индекса",
                              "Недопустимое значение индекса");
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "error", QString("Error: ") + e.what());
    }

    VisualVector2();
}

void MainWindow::SizeHelper2() {
    ui->resultEdit2->clear();
    ui->resultEdit2->setText(QString::number(vector_2.size()));
}

void MainWindow::PopBackHelper2() {
    try {
        vector_2.pop_back();
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "error", QString("Error: ") + e.what());
    }
    VisualVector2();
}

void MainWindow::AtHelper2() {
    QString input = ui->indexEdit2->text();
    ui->indexEdit2->clear();

    if (!CheckInt(input)) {
        Error();
        return;
    }

    try {
        int index = input.toInt();
        ui->resultEdit2->clear();

        const Pair<int, double>& pair = vector_2.at(index);

        QString result =
            QString("(%1, %2)").arg(pair.first).arg(pair.second, 0, 'f', 2);

        ui->resultEdit2->setText(result);
    }

    catch (const std::out_of_range& e) {
        QMessageBox::critical(this, "Ошибка индекса",
                              "Индекс выходит за границы вектора");
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "Ошибка",
                              QString("Произошла ошибка: ") + e.what());
    }

    VisualVector2();
}

void MainWindow::EraseHelper2() {
    QString input = ui->indexEdit2->text();
    ui->indexEdit->clear();

    if (!CheckInt(input)) {
        Error();
        return;
    }

    try {
        int index = input.toInt();

        if (vector_2.empty()) {
            QMessageBox::information(this, "Информация",
                                     "Вектор пуст, удалять нечего");
            return;
        }

        if (index < 0 || index >= static_cast<int>(vector_2.size())) {
            throw std::out_of_range("Индекс выходит за границы вектора");
        }

        vector_2.erase(vector_2.begin() + index);

    }

    catch (const std::out_of_range& e) {
        QMessageBox::critical(
            this, "Ошибка индекса",
            QString("Недопустимый индекс. Допустимый диапазон: 0..%1")
                .arg(vector_2.size() - 1));
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "Ошибка",
                              QString("Произошла ошибка: ") + e.what());
    }

    VisualVector2();
}

void MainWindow::InsertHelper2() {
    QString inputInt = ui->valueEdit->text();
    QString inputDouble = ui->value2Edit2->text();
    QString inputIndex = ui->indexEdit->text();

    ui->valueEdit->clear();
    ui->value2Edit2->clear();
    ui->indexEdit->clear();

    if (!CheckInt(inputInt) || !CheckInt(inputIndex)) {
        Error();
        return;
    }
    if (!CheckDouble(inputDouble)) {
        ErrorDouble();
        return;
    }

    try {
        int intValue = inputInt.toInt();
        double doubleValue = inputDouble.toDouble();
        int index = inputIndex.toInt();

        if (index < 0 || index > static_cast<int>(vector_2.size())) {
            throw std::out_of_range("Invalid index");
        }

        Pair<int, double> newPair(intValue, doubleValue);

        vector_2.insert(vector_2.begin() + index, newPair);

    }

    catch (const std::out_of_range& e) {
        QMessageBox::critical(
            this, "Ошибка индекса",
            QString("Недопустимый индекс. Допустимый диапазон: 0..%1")
                .arg(vector_2.size()));
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "Ошибка",
                              QString("Произошла ошибка: ") + e.what());
    }

    VisualVector2();
}

void MainWindow::ClearHelper2() {
    vector_2.clear();
    VisualVector2();
}

void MainWindow::CapacityHelper2() {
    ui->resultEdit2->clear();
    ui->resultEdit2->setText(QString::number(vector_2.capacity()));
}

void MainWindow::MaxSizeHelper2() {
    ui->resultEdit2->clear();
    ui->resultEdit2->setText(QString::number(vector_2.max_size()));
}


//---------------------------------------------------------------------

void MainWindow::ReserveHelper3() {
    QString input = ui->forresizeEdit3->text();
    ui->forresizeEdit3->clear();

    if (!CheckInt(input)) {
        Error();
        return;
    }

    try {
        int n = input.toInt();
        if (n < 0) {
            throw std::invalid_argument("Размер не может быть отрицательным");
        }

        container_.reserve(n);

    }

    catch (const std::invalid_argument& e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "Ошибка",
                              QString("Произошла ошибка: ") + e.what());
    }
}

void MainWindow::ResizeHelper3() {
    QString inputSize = ui->forresizeEdit3->text();
    ui->forresizeEdit3->clear();

    if (!CheckInt(inputSize)) {
        Error();
        return;
    }

    try {
        int newSize = inputSize.toInt();
        if (newSize < 0) {
            throw std::invalid_argument("Размер не может быть отрицательным");
        }

        bool useCurrentVectors = !vector_.empty() || !vector_2.empty();

        Pair<Vector<int>, Vector<Pair<int, double>>> fillPair;
        if (useCurrentVectors) {
            fillPair =
                Pair<Vector<int>, Vector<Pair<int, double>>>(vector_, vector_2);

        } else {
            fillPair = Pair<Vector<int>, Vector<Pair<int, double>>>(
                Vector<int>(), Vector<Pair<int, double>>());
        }

        container_.resize(newSize, fillPair);

    }

    catch (const std::invalid_argument& e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }

    catch (const std::exception& e) {
        QMessageBox::critical(
            this, "Ошибка",
            QString("Произошла ошибка при изменении размера: ") + e.what());
    }

    VisualVector3();
}

void MainWindow::AssignHelper3() {
    QString inputSize = ui->forresizeEdit3->text();
    ui->forresizeEdit3->clear();

    if (!CheckInt(inputSize)) {
        Error();
        return;
    }

    try {
        int newSize = inputSize.toInt();
        if (newSize < 0) {
            throw std::invalid_argument("Размер не может быть отрицательным");
        }

        Vector<int> currentVector1 = vector_;
        Vector<Pair<int, double>> currentVector2 = vector_2;


        container_.clear();


        for (int i = 0; i < newSize; ++i) {
            Vector<int> newVector1 = currentVector1;
            Vector<Pair<int, double>> newVector2 = currentVector2;

            container_.push_back(Pair<Vector<int>, Vector<Pair<int, double>>>(
                newVector1, newVector2));
        }

    }

    catch (const std::invalid_argument& e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }

    catch (const std::exception& e) {
        QMessageBox::critical(
            this, "Ошибка",
            QString("Произошла ошибка при заполнении: ") + e.what());
    }

    VisualVector3();
}

void MainWindow::PushBackHelper3() {
    if (vector_.empty() && vector_2.empty()) {
        QMessageBox::information(
            this, "Информация",
            "Оба рабочих вектора пусты. Добавьте данные сначала.");
        return;
    }

    try {
        Pair<Vector<int>, Vector<Pair<int, double>>> newPair(vector_, vector_2);

        container_.push_back(newPair);
    }

    catch (const std::exception& e) {
        QMessageBox::critical(
            this, "Ошибка",
            QString("Произошла ошибка при добавлении: ") + e.what());
    }

    VisualVector3();
}

void MainWindow::EmplaceBackHelper3() {
    if (vector_.empty() && vector_2.empty()) {
        QMessageBox::information(
            this, "Информация",
            "Рабочие векторы пусты. Добавьте данные сначала.");
        return;
    }

    try {
        container_.emplace_back(vector_, vector_2);
    }

    catch (const std::bad_alloc& e) {
        QMessageBox::critical(this, "Ошибка памяти",
                              "Недостаточно памяти для добавления элемента");
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "Ошибка",
                              QString("Ошибка при добавлении: ") + e.what());
    }

    VisualVector3();
}

void MainWindow::EmplaceHelper3() {
    if (vector_.empty() && vector_2.empty()) {
        QMessageBox::information(
            this, "Информация",
            "Рабочие векторы пусты. Добавьте данные сначала.");
        return;
    }

    QString inputIndex = ui->indexEdit3->text();
    ui->indexEdit3->clear();

    if (!CheckInt(inputIndex)) {
        Error();
        return;
    }

    try {
        int index = inputIndex.toInt();
        if (index < 0 || index > static_cast<int>(container_.size())) {
            throw std::out_of_range(
                QString("Индекс должен быть в диапазоне [0, %1]")
                    .arg(container_.size())
                    .toStdString());
        }

        container_.emplace(container_.begin() + index, vector_, vector_2);
    }

    catch (const std::out_of_range& e) {
        QMessageBox::critical(this, "Ошибка индекса", e.what());
    }

    catch (const std::bad_alloc& e) {
        QMessageBox::critical(this, "Ошибка памяти",
                              "Недостаточно памяти для вставки элемента");
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "Ошибка",
                              QString("Ошибка при вставке: %1").arg(e.what()));
    }

    VisualVector3();
}

void MainWindow::SizeHelper3() {
    ui->resultEdit3->clear();
    ui->resultEdit3->setText(QString::number(container_.size()));
}

void MainWindow::PopBackHelper3() {
    try {
        if (container_.empty()) {
            QMessageBox::information(this, "Информация",
                                     "Контейнер пуст, удалять нечего");
            return;
        }

        container_.pop_back();

    }

    catch (const std::exception& e) {
        QMessageBox::critical(
            this, "Ошибка",
            QString("Произошла ошибка при удалении: ") + e.what());
    }

    VisualVector3();
}

void MainWindow::AtHelper3() {
    QString input = ui->indexEdit3->text();
    ui->indexEdit3->clear();

    if (!CheckInt(input)) {
        Error();
        return;
    }

    try {
        int index = input.toInt();
        ui->resultEdit3->clear();

        if (container_.empty()) {
            throw std::out_of_range("Контейнер пуст");
        }

        const auto& containerItem = container_.at(index);

        QString intVectorStr = "[";


        for (const auto& num : containerItem.first) {
            intVectorStr += QString::number(num) + " ";
        }
        intVectorStr += "]";

        QString pairVectorStr = "[";


        for (const auto& p : containerItem.second) {
            pairVectorStr +=
                QString("(%1, %2) ").arg(p.first).arg(p.second, 0, 'f', 2);
        }
        pairVectorStr += "]";

        QString result = QString("Элемент %1:\nВектор int: %2\nВектор пар: %3")
                             .arg(index)
                             .arg(intVectorStr)
                             .arg(pairVectorStr);

        ui->resultEdit3->setText(result);
    }

    catch (const std::out_of_range& e) {
        QString errorMsg =
            QString("Ошибка индекса: %1\nДопустимый диапазон: 0..%2")
                .arg(e.what())
                .arg(container_.empty() ? 0 : container_.size() - 1);
        QMessageBox::critical(this, "Ошибка", errorMsg);
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "Ошибка",
                              QString("Произошла ошибка: ") + e.what());
    }

    VisualVector3();
}

void MainWindow::EraseHelper3() {
    QString input = ui->indexEdit3->text();
    ui->indexEdit3->clear();

    if (!CheckInt(input)) {
        Error();
        return;
    }

    try {
        int index = input.toInt();

        if (container_.empty()) {
            QMessageBox::information(this, "Информация",
                                     "Контейнер пуст, удалять нечего");
            return;
        }

        if (index < 0 || index >= static_cast<int>(container_.size())) {
            throw std::out_of_range("Индекс выходит за границы контейнера");
        }

        container_.erase(container_.begin() + index);

    }

    catch (const std::out_of_range& e) {
        QMessageBox::critical(
            this, "Ошибка индекса",
            QString("Недопустимый индекс. Допустимый диапазон: 0..%1\n"
                    "Текущий размер контейнера: %2")
                .arg(container_.size() - 1)
                .arg(container_.size()));
    }

    catch (const std::exception& e) {
        QMessageBox::critical(
            this, "Ошибка",
            QString("Произошла ошибка при удалении: ") + e.what());
    }

    VisualVector3();
}

void MainWindow::InsertHelper3() {
    QString inputIndex = ui->indexEdit3->text();
    ui->indexEdit3->clear();

    if (!CheckInt(inputIndex)) {
        Error();
        return;
    }

    if (vector_.empty() && vector_2.empty()) {
        QMessageBox::information(
            this, "Информация",
            "Рабочие векторы пусты. Добавьте данные сначала.");
        return;
    }

    try {
        int index = inputIndex.toInt();

        if (index < 0 || index > static_cast<int>(container_.size())) {
            throw std::out_of_range(
                QString("Индекс должен быть в диапазоне [0, %1]")
                    .arg(container_.size())
                    .toStdString());
        }

        Pair<Vector<int>, Vector<Pair<int, double>>> newPair(vector_, vector_2);

        container_.insert(container_.begin() + index, newPair);

    }

    catch (const std::out_of_range& e) {
        QMessageBox::critical(
            this, "Ошибка индекса",
            QString("Недопустимый индекс: %1\nДопустимый диапазон: 0..%2")
                .arg(e.what())
                .arg(container_.size()));
    }

    catch (const std::bad_alloc& e) {
        QMessageBox::critical(this, "Ошибка памяти",
                              "Недостаточно памяти для вставки элемента");
    }

    catch (const std::exception& e) {
        QMessageBox::critical(this, "Ошибка",
                              QString("Ошибка при вставке: %1").arg(e.what()));
    }

    VisualVector2();
}

void MainWindow::ClearHelper3() {
    container_.clear();
    VisualVector3();
}

void MainWindow::CapacityHelper3() {
    ui->resultEdit3->clear();
    ui->resultEdit3->setText(QString::number(container_.capacity()));
}

void MainWindow::MaxSizeHelper3() {
    ui->resultEdit3->clear();
    ui->resultEdit3->setText(QString::number(container_.max_size()));
}
