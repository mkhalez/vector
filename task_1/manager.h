#ifndef MANAGER_H
#define MANAGER_H
#include <QString>

class Manager {
   public:
    Manager();
    ~Manager();
    int* list_of_number;
    int size;
    int* AddElement(int* list_of_number, int& size);
    void QuickSort(int* arr, int left, int right);
    int Partition(int* list_of_number, int low, int high);

    void HeapSort(int* arr, int size);

    void MergeSort(int* arr, int left, int right);
    int BinarySearch(int* arr, int low, int high, int x);
    void ClearArray(int*& arr, int& size);
    bool Valid(QString input);

   private:
    void Heapify(int* arr, int n, int i);
    void Merge(int* arr, int left, int mid, int right);
};

#endif	// MANAGER_H
