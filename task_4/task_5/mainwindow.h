#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector.h>
#include <QMainWindow>

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

    Vector<int> vector_;

    bool CheckInt(QString input);
    void Error();
    void VisualVector();

   private slots:
    void ReserveHelper();
    void ResizeHelper();
    void AssignHelper();
    void PushBackHelper();
    void EmplaceBackHelper();
    void EmplaceHelper();
    void SizeHelper();
    void PopBackHelper();
    void AtHelper();
    void EraseHelper();
    void InsertHelper();
    void ClearHelper();
    void CapacityHelper();
    void MaxSizeHelper();
};
#endif	// MAINWINDOW_H
