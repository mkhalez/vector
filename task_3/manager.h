#ifndef MANAGER_H
#define MANAGER_H

#include <QVector>

class Manager {
   public:
    Manager();
    QVector<int> Calculate(QVector<int> arr);
    void AddNumber(int number);
    QVector<int> arr;
    void Clear();
    bool Valid(QString input);

   private:
    QVector<int> result;
};

#endif	// MANAGER_H
