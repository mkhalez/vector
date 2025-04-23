#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "manager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();


   private:
    Ui::MainWindow* ui;
    Manager manager_;
    void InterpolationSort(int* arr, int size, bool is_sort);
    void VisualArray();
    QTimer* sortTimer;
    void UpdateVisualization(int* arr, int size);

   private slots:
    void AddNumber();
    void SortHelper();
    void FindHelper();
    void ClearHelper();
};
#endif	// MAINWINDOW_H
