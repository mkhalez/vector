#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QThread>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    manager_.size = 0;
    manager_.list_of_number = new int[manager_.size];

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::AddNumber);
    connect(ui->sortButton, &QPushButton::clicked, this,
            &MainWindow::SortHelper);
    connect(ui->findButton, &QPushButton::clicked, this,
            &MainWindow::FindHelper);
    connect(ui->clearButton, &QPushButton::clicked, this,
            &MainWindow::ClearHelper);
    sortTimer = new QTimer(this);
}

MainWindow::~MainWindow() {
    delete ui;
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
        InterpolationSort(manager_.list_of_number, manager_.size, true);
        VisualArray();
    } else {
        QMessageBox::warning(this, "Error", "array is empty", QMessageBox::Ok);
    }
}

void MainWindow::FindHelper() {
    ui->resulEdit->clear();
    ui->binpowEdit->clear();
    QString input = ui->inputFind->text();
    if (manager_.Valid(input)) {
        int our_number = input.toInt();
        InterpolationSort(manager_.list_of_number, manager_.size, false);
        VisualArray();
        int index = manager_.BinarySearch(manager_.list_of_number, 0,
                                          manager_.size - 1, our_number);
        ui->resulEdit->setText(QString::number(index));
        ui->binpowEdit->setText(QString::number(manager_.BinPow(
            index, manager_.size, manager_.list_of_number[index])));
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

/*int MainWindow::Partition(int* arr, int low, int high) {
    if (low >= high)
        return low;

    int minVal = arr[low], maxVal = arr[low];


    for (int i = low + 1; i <= high; ++i) {
        if (arr[i] < minVal)
            minVal = arr[i];
        else if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    if (minVal == maxVal)
        return low;

    double pivotVal = minVal + (maxVal - minVal) / 2.0;

    int pos = low + static_cast<int>((pivotVal - minVal) * (high - low) /
                                     (maxVal - minVal));

    pos = std::max(low, std::min(pos, high));

    std::swap(arr[pos], arr[high]);

    int pivot = arr[high];
    int i = low - 1;


    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}*/

void MainWindow::UpdateVisualization(int* arr, int size) {
    QString output;


    for (int i = 0; i < size; i++) {
        output += QString::number(arr[i]) + " ";
    }
    ui->arrayEdit->setText(output);

    // Принудительно обрабатываем события
    QCoreApplication::processEvents();
}

void MainWindow::InterpolationSort(int* arr, int size, bool is_sort) {
    if (size <= 1)
        return;

    // Стек для хранения границ сегментов [left, right]
    int* stack = new int[2 * size]();  // Инициализируем нулями
    int stackTop = 0;

    // Инициализация - весь массив как первый сегмент
    stack[stackTop++] = 0;
    stack[stackTop++] = size - 1;


    while (stackTop > 0) {
        // Извлекаем границы текущего сегмента
        int right = stack[--stackTop];
        int left = stack[--stackTop];

        if (left >= right)
            continue;

        // Визуализация текущего состояния
        UpdateVisualization(arr, size);
        if (is_sort)
            QThread::msleep(500);

        // Находим минимальный и максимальный элементы
        int minVal = arr[left];
        int maxVal = arr[left];
        for (int i = left + 1; i <= right; ++i) {
            if (arr[i] < minVal)
                minVal = arr[i];
            if (arr[i] > maxVal)
                maxVal = arr[i];
        }

        // Если все элементы одинаковые, сегмент отсортирован
        if (minVal == maxVal)
            continue;

        // Создаем корзины
        int bucketCount = right - left + 1;
        int** buckets =
            new int*[bucketCount]();  // Инициализируем нулевыми указателями
        int* bucketSizes = new int[bucketCount]();	// Инициализируем нулями

        // Выделяем память для корзин (максимально возможный размер)
        for (int i = 0; i < bucketCount; ++i) {
            buckets[i] = new int[right - left + 1]();  // Инициализируем нулями
        }

        // Распределяем элементы по корзинам
        for (int i = left; i <= right; ++i) {
            if (maxVal == minVal)
                continue;  // Защита от деления на ноль

            double fraction =
                static_cast<double>(arr[i] - minVal) / (maxVal - minVal);
            int bucketIndex = static_cast<int>(fraction * (bucketCount - 1));
            bucketIndex = std::max(
                0, std::min(bucketIndex,
                            bucketCount - 1));	// Ограничиваем диапазон

            buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
        }

        // Визуализация после распределения по корзинам
        UpdateVisualization(arr, size);
        if (is_sort)
            QThread::msleep(500);

        // Собираем элементы обратно в массив и добавляем новые сегменты в стек
        int index = left;
        for (int i = 0; i < bucketCount; ++i) {
            if (bucketSizes[i] > 0) {
                // Добавляем границы сегмента в стек, если в корзине больше 1 элемента
                if (bucketSizes[i] > 1) {
                    if (stackTop + 2 <=
                        2 * size) {	 // Проверка на переполнение стека
                        stack[stackTop++] = index;
                        stack[stackTop++] = index + bucketSizes[i] - 1;
                    }
                }

                // Копируем элементы из корзины в массив
                for (int j = 0; j < bucketSizes[i]; ++j) {
                    if (index < size) {	 // Проверка границ массива
                        arr[index++] = buckets[i][j];
                    }
                }

                // Визуализация после копирования элементов из корзины
                UpdateVisualization(arr, size);
                if (is_sort)
                    QThread::msleep(500);

                // Освобождаем память корзины
                delete[] buckets[i];
                buckets[i] = nullptr;  // Явное обнуление указателя
            }
        }

        // Освобождаем вспомогательные массивы
        delete[] buckets;
        delete[] bucketSizes;
    }

    delete[] stack;
    stack = nullptr;  // Явное обнуление указателя
}

void MainWindow::VisualArray() {
    ui->arrayEdit->clear();
    QString output = "";
    for (int i = 0; i < manager_.size; i++) {
        output += QString::number(manager_.list_of_number[i]) + " ";
    }
    ui->arrayEdit->setText(output);
}
