#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn_0, SIGNAL(released()),this, SLOT(press()));
    connect(ui->btn_1, SIGNAL(released()),this, SLOT(press()));
    connect(ui->btn_2, SIGNAL(released()),this, SLOT(press()));
    connect(ui->btn_3, SIGNAL(released()),this, SLOT(press()));
    connect(ui->btn_4, SIGNAL(released()),this, SLOT(press()));
    connect(ui->btn_5, SIGNAL(released()),this, SLOT(press()));
    connect(ui->btn_6, SIGNAL(released()),this, SLOT(press()));
    connect(ui->btn_7, SIGNAL(released()),this, SLOT(press()));
    connect(ui->btn_8, SIGNAL(released()),this, SLOT(press()));
    connect(ui->btn_9, SIGNAL(released()),this, SLOT(press()));

}

void MainWindow::press()
{
}

MainWindow::~MainWindow()
{
    delete ui;
}
