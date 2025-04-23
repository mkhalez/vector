#include "manager.h"

Manager::Manager() {}

QVector<int> Manager::Calculate(QVector<int> arr) {
    int size = arr.size();


    for (int i = 0; i < size; i = i + 3) {
        if (i + 2 <= size - 1) {
            int a = arr[i];
            int b = arr[i + 1];
            int c = arr[i + 2];
            int our_number = a + b + c - std::min(a, std::min(b, c)) -
                             std::max(a, std::max(b, c));
            result.push_back(our_number);
        } else if (i + 1 <= size - 1) {
            int a = arr[i];
            int b = arr[i + 1];
            result.push_back((a + b) / 2);
        } else {
            result.push_back(arr[i]);
        }
    }
    return result;
}

void Manager::AddNumber(int number) {
    arr.push_back(number);
}

void Manager::Clear() {
    result.clear();
    arr.clear();
}

bool Manager::Valid(QString input) {
    bool ok;
    input.toInt(&ok);
    return ok;
}
