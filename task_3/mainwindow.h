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
    void VisualArray();
    void VisualResult(QVector<int> array);

   private slots:
    void AddNumberHelper();
    void CalculateHelper();
    void ClearHelper();
};
#endif	// MAINWINDOW_H
