#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <pair.h>
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

    Vector<Pair<int, double>> vector_2;

    bool CheckInt(QString input);
    bool CheckDouble(QString input);
    void Error();
    void ErrorDouble();
    void VisualVector();
    void VisualVector2();
    void VisualVector3();

    Vector<Pair<Vector<int>, Vector<Pair<int, double>>>> container_;

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

    void ReserveHelper2();
    void ResizeHelper2();
    void AssignHelper2();
    void PushBackHelper2();
    void EmplaceBackHelper2();
    void EmplaceHelper2();
    void SizeHelper2();
    void PopBackHelper2();
    void AtHelper2();
    void EraseHelper2();
    void InsertHelper2();
    void ClearHelper2();
    void CapacityHelper2();
    void MaxSizeHelper2();

    void ReserveHelper3();
    void ResizeHelper3();
    void AssignHelper3();
    void PushBackHelper3();
    void EmplaceBackHelper3();
    void EmplaceHelper3();
    void SizeHelper3();
    void PopBackHelper3();
    void AtHelper3();
    void EraseHelper3();
    void InsertHelper3();
    void ClearHelper3();
    void CapacityHelper3();
    void MaxSizeHelper3();
};
#endif	// MAINWINDOW_H
