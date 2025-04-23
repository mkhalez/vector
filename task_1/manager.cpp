#include "manager.h"
#include <utility>

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

void Manager::QuickSort(int* arr, int left, int right) {
    if (left >= right)
        return;

    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;


    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        QuickSort(arr, left, j);
    if (i < right)
        QuickSort(arr, i, right);
}

void Manager::Heapify(int* arr, int n, int i) {

    int largest = i;

    int l = 2 * i + 1;

    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        Heapify(arr, n, largest);
    }
}

void Manager::HeapSort(int* arr, int size) {
    int n = size;

    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);


    for (int i = n - 1; i > 0; i--) {

        std::swap(arr[0], arr[i]);

        Heapify(arr, i, 0);
    }
}

void Manager::Merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;


    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void Manager::MergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        Merge(arr, left, mid, right);
    }
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
