#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tableWidget_cellClicked(int row, int column);

    void on_actionAdd_Walls_triggered();

    void on_actionAdd_Start_triggered();

    void on_actionAdd_End_triggered();

    void on_actionCancel_Current_Action_triggered();

    void on_actionClear_grid_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
