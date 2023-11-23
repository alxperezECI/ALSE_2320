#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <eigen3/Eigen/Dense>
#include "dialog.h"

using Eigen::MatrixXd;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _tipoDivision = 0;
    _escalar = 0.;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tipoDivi(int tipo, double escalar){
    _escalar = escalar;
    _tipoDivision = tipo;
}


void MainWindow::on_pushButton_clicked()
{
    MatrixXd A(2,2), B(2,2), R(2,2);
    A(0,0)=ui->lineEdit->text().toDouble();
    A(0,1)=ui->lineEdit_2->text().toDouble();
    A(1,0)=ui->lineEdit_3->text().toDouble();
    A(1,1)=ui->lineEdit_4->text().toDouble();
    B(0,0)=ui->lineEdit_9->text().toDouble();
    B(0,1)=ui->lineEdit_10->text().toDouble();
    B(1,0)=ui->lineEdit_11->text().toDouble();
    B(1,1)=ui->lineEdit_12->text().toDouble();
    switch (ui->selec->currentIndex()) {
    case 0:
        R = A + B;
        break;
    case 1:
        R = A - B;
        break;
    case 2:
        R = A * B;
        break;
    case 3:
        Dialog emrg;
        connect(&emrg,  &Dialog::senalDivi, this, &MainWindow::tipoDivi);
        emrg.setModal(true);
        emrg.show();
        emrg.exec();
        switch( _tipoDivision ){
            case 0:
                R = A * B.inverse(); break;
            case 1:
                R = A.inverse() * B; break;
            case 2:
                R = A / _escalar; break;
            case 3:
                R = B / _escalar; break;
            }
            break;
    }
    ui->lineEdit_13->setText(QString::number(R(0,0)));
    ui->lineEdit_14->setText(QString::number(R(0,1)));
    ui->lineEdit_15->setText(QString::number(R(1,0)));
    ui->lineEdit_16->setText(QString::number(R(1,1)));

}

