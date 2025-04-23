#include "manager.h"

Manager::Manager() {}

Manager::~Manager() {
    delete[] list_of_number;
}

int* Manager::AddElement(int* list_of_number, int& size) {
    int* new_list = new int[size + 1];


    for (int i = 0; i < size; i++) {
        new_list[i] = list_of_number[i];
    }
    delete[] list_of_number;
    size++;
    return new_list;
}

int Manager::BinarySearch(int* arr, int low, int high, int x) {


    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

void Manager::ClearArray(int*& arr, int& size) {
    delete[] arr;
    size = 0;
    arr = new int[size];
}

bool Manager::Valid(QString input) {
    bool ok;
    input.toInt(&ok);
    return ok;
}

int Manager::BinPow(int digit, int powder, int mod) {
    int result = 1;
    digit %= mod;


    while (powder > 0) {
        if (powder % 2 == 1) {
            result = (result * digit) % mod;
        }

        digit = (digit * digit) % mod;
        powder /= 2;
    }
    return result;
}
