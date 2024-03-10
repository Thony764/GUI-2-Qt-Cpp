#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Conectar la señal clicked de todos los botones dentro de frame_lateral
    QList<QPushButton *> botones = ui->frame_lateral->findChildren<QPushButton *>();
    for (QPushButton *btn : botones)
    {
        connect(btn, &QPushButton::clicked, this, [=]() { actualizarEstiloBoton(btn); });

        // Establecer la política de tamaño mínimo
        btn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        btn->setMinimumHeight(40);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizarEstiloBoton(QPushButton *botonPresionado)
{
    // Limpiar el estilo de todos los botones dentro de frame_lateral
    QList<QPushButton *> botones = ui->frame_lateral->findChildren<QPushButton *>();
    QString estiloNormal = "QPushButton { }";
    QString estiloPresionado = "QPushButton { background-color: #323A4F; }"
                               "QPushButton:pressed {"
                               "    color: white;"
                               "}";

    for (QPushButton *btn : botones)
    {
        btn->setStyleSheet(estiloNormal);
    }

    // Aplicar el estilo al botón presionado
    botonPresionado->setStyleSheet(estiloPresionado);
}

void MainWindow::on_btn_menu_clicked()
{
    if (isFrameLateralCollapsed)
    {
        // Expandir el frame lateral
        ui->frame_lateral->setMaximumWidth(expandedWidth);
        ui->btn_menu->setIcon(QIcon(":/img/icon_light/menu.svg"));

        isFrameLateralCollapsed = false;
    }
    else
    {
        // Colapsar el frame lateral
        ui->frame_lateral->setMaximumWidth(collapsedWidth);
        ui->btn_menu->setIcon(QIcon(":/img/icon_light/chevron-left.svg"));

        isFrameLateralCollapsed = true;
    }

    // Actualizar el estilo de los botones al hacer clic en el botón de menú
    actualizarEstiloBoton(ui->btn_menu);
}
