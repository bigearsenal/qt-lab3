#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmath.h"
double firstNumber;

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
    connect(ui->btn_dot, SIGNAL(released()),this, SLOT(press()));

    connect(ui->btn_plus, SIGNAL(released()),this, SLOT(basicOperation()));
    connect(ui->btn_minus, SIGNAL(released()),this, SLOT(basicOperation()));
    connect(ui->btn_multiplicate, SIGNAL(released()),this, SLOT(basicOperation()));
    connect(ui->btn_devide, SIGNAL(released()),this, SLOT(basicOperation()));

    ui->btn_plus->setCheckable(true);
    ui->btn_minus->setCheckable(true);
    ui->btn_devide->setCheckable(true);
    ui->btn_multiplicate->setCheckable(true);

    connect(ui->btn_equal, SIGNAL(released()),this, SLOT(solveOperation()));

    connect(ui->btn_C, SIGNAL(released()),this, SLOT(clear()));
    connect(ui->btn_plus_minus, SIGNAL(released()),this, SLOT(minus_plus()));


    connect(ui->btn_sin, SIGNAL(released()),this, SLOT(sin_cos_log()));
    connect(ui->btn_cos, SIGNAL(released()),this, SLOT(sin_cos_log()));
    connect(ui->btn_log, SIGNAL(released()),this, SLOT(sin_cos_log()));

}

void MainWindow::press()
{

    QPushButton * button= (QPushButton*)sender();

    if (button->text() == "." && !(ui->label->text().contains("."))) {
        ui->label->setText(ui->label->text()+button->text());
        return;
    }

    double Number;
    QString newLabel;
    Number=(ui->label->text()+button->text()).toDouble();
    newLabel= QString::number(Number);
    ui->label->setText(newLabel);
}

void MainWindow::basicOperation() {
    QPushButton * button= (QPushButton*)sender();
    firstNumber= ui->label->text().toDouble();
    button->setChecked(true);
    ui->label->setText("0");
}

void MainWindow::solveOperation() {
    double labelNumber,secondNumber;
    QString newLabel;
    secondNumber= ui->label->text().toDouble();
    if(ui->btn_plus->isChecked())
    {
        labelNumber= firstNumber+ secondNumber;
        newLabel= QString::number(labelNumber,'g','15');
        ui->label->setText(newLabel);
        ui->btn_plus->setChecked(false);
    }
    else if(ui->btn_minus->isChecked())
    {
        labelNumber= firstNumber-secondNumber;
        newLabel= QString::number(labelNumber);
        ui->label->setText(newLabel);
        ui->btn_minus->setChecked(false);
    }
    else if(ui->btn_devide->isChecked())
    {
        labelNumber= firstNumber/secondNumber;
        newLabel= QString::number(labelNumber);
        ui->label->setText(newLabel);
        ui->btn_devide->setChecked(false);
    }
    else if(ui->btn_multiplicate->isChecked())
    {
        labelNumber= firstNumber*secondNumber;
        newLabel= QString::number(labelNumber);
        ui->label->setText(newLabel);
        ui->btn_multiplicate->setChecked(false);

    }
}

void MainWindow::clear() {
    ui->label->setText("0");
}

void MainWindow::minus_plus() {
    double number=(ui->label->text()).toDouble();
    ui->label->setText(QString::number(-number));
}

void MainWindow::sin_cos_log() {
    QPushButton * button= (QPushButton*)sender();
    if (button->text() == "sin") {
        double result = sin(ui->label->text().toDouble());
        ui->label->setText(QString::number(result));
    } else if (button->text() == "cos") {
        double result = cos(ui->label->text().toDouble());
        ui->label->setText(QString::number(result));
    } else {
        double result = log(ui->label->text().toDouble());
        ui->label->setText(QString::number(result));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
