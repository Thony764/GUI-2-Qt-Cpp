#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_menu_clicked();
    void actualizarEstiloBoton(QPushButton *botonPresionado);

private:
    Ui::MainWindow *ui;
    bool isFrameLateralCollapsed = false;
    const int collapsedWidth = 0;
    const int expandedWidth = 16777215;
};

#endif // MAINWINDOW_H
