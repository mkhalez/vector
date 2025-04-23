#ifndef MANAGER_H
#define MANAGER_H
#include <QString>
#include <QTimer>

class Manager {
   public:
    Manager();
    ~Manager();
    int* list_of_number;
    int size;
    int* AddElement(int* list_of_number, int& size);

    int BinarySearch(int* arr, int low, int high, int x);
    void ClearArray(int*& arr, int& size);
    bool Valid(QString input);

    int BinPow(int digit, int powder, int mod);

   private:
};

#endif	// MANAGER_H
