#include "vantana.h"
#include "./ui_vantana.h"
#include "divi_diag.h"
#include <eigen3/Eigen/Dense>

using Eigen::MatrixXd;


vantana::vantana(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::vantana)
{
    ui->setupUi(this);
    _tipoDivision = 0;
    _escalar = 0.;
}

vantana::~vantana()
{
    delete ui;
}

void vantana::tipoDivi(int tipo, double escalar){
    _escalar = escalar;
    _tipoDivision = tipo;
}

void vantana::on_cmd_Operacion_clicked(){

    // Construir las matrices A y B con los datos de la interface
    MatrixXd A(2,2), B(2,2), R(2,2);
    A(0,0) = ui->txt_A11->text().toDouble();
    A(0,1) = ui->txt_A12->text().toDouble();

    switch( ui->cbx_Operacion->currentIndex()){
        case 0: // Suma
            R = A + B;
            break;
        case 1: // Resta
            ui->txt_A11->setText("-");
            break;
        case 2: // Multiplicación
            ui->txt_A11->setText("*");
            break;
        case 3:  // Division
            // Crear una ventana emergente
            Divi_diag dialogo;
            connect( &dialogo, &Divi_diag::senalDivi, this, &vantana::tipoDivi );
            dialogo.setModal(true);
            dialogo.show();
            dialogo.exec();
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

    // Escribir el resultado de la matriz respuesta en la interface.
    ui->txt_R11->setText( QString::number( R(0,0) ) );
}
