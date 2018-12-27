#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void press();
    void basicOperation();
    void solveOperation();
    void clear();
    void minus_plus();
    void sin_cos_log();
};

#endif // MAINWINDOW_H
