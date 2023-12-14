#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <eigen3/Eigen/Dense>

#include <QDebug>
#include <stdlib.h>
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

using Eigen::MatrixXd;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Agregar el icono de archivo a la ventana
    setWindowIcon(QIcon("../jirafa/alse.png"));

    timer = new QTimer(this);

    // Conecta el temporizador a la función que manejará la actualización
    connect(timer, &QTimer::timeout, this, &MainWindow::actualizarCadaMinuto);


    actualizarCadaMinuto();

    // Configura el temporizador para que se ejecute cada minuto (60000 milisegundos)
    timer->start(60000); // 60000
}

MainWindow::~MainWindow()
{
    delete ui;
}

MatrixXd MainWindow::abrir_db()
{
    MatrixXd R(6,3);
if (!QSqlDatabase::isDriverAvailable("QSQLITE")){
    qDebug()<<"Error: QSQLITE no está disponible";}

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName( "../jirafa/base_aguacate.db");
    if (db.open())                             // abre la base de datos
    {
        qDebug() << "Base de datos abierta";
    }
    else
    {
        qDebug() << "Error al abrir la base de datos";
    }


    QString consultaHumedad = "SELECT maximo, promedio, minimo FROM humedad";
    QSqlQuery query(db);
    if (query.exec(consultaHumedad)) {
        if (query.next()) {
            double maximo = query.value(0).toDouble();
            double promedio = query.value(1).toDouble();
            double minimo = query.value(2).toDouble();
            qDebug() << "Máximo:" << maximo << "Promedio:" << promedio << "Mínimo:" << minimo;
           }
    }
    QString consultatemp = "SELECT maximo, promedio, minimo FROM temperatura";
    QSqlQuery temp(db);
    if (temp.exec(consultatemp)) {
        if (temp.next()) {
            double maximo = temp.value(0).toDouble();
            double promedio = temp.value(1).toDouble();
            double minimo = temp.value(2).toDouble();
            qDebug() << "Máximo:" << maximo << "Promedio:" << promedio << "Mínimo:" << minimo;
        }
    }
    QString consultaluz = "SELECT maximo, promedio, minimo FROM luz";
    QSqlQuery luz(db);
    if (luz.exec(consultaluz)) {
        if (luz.next()) {
            double maximo = luz.value(0).toDouble();
            double promedio = luz.value(1).toDouble();
            double minimo = luz.value(2).toDouble();
            qDebug() << "Máximo:" << maximo << "Promedio:" << promedio << "Mínimo:" << minimo;
        }
    }
    QString consultaprec = "SELECT maximo, promedio, minimo FROM precipitacion";
    QSqlQuery prec(db);
    if (prec.exec(consultaprec)) {
        if (prec.next()) {
            double maximo = prec.value(0).toDouble();
            double promedio = prec.value(1).toDouble();
            double minimo = prec.value(2).toDouble();
            qDebug() << "Máximo:" << maximo << "Promedio:" << promedio << "Mínimo:" << minimo;
        }
    }
    QString consultavel = "SELECT maximo, promedio, minimo FROM velocidad";
    QSqlQuery vel(db);
    if (vel.exec(consultavel)) {
        if (vel.next()) {
            double maximo = vel.value(0).toDouble();
            double promedio = vel.value(1).toDouble();
            double minimo = vel.value(2).toDouble();
            qDebug() << "Máximo:" << maximo << "Promedio:" << promedio << "Mínimo:" << minimo;
        }
    }
    QString consultavie = "SELECT maximo, promedio, minimo FROM viento";
    QSqlQuery vie(db);
    if (vie.exec(consultavie)) {
        if (vie.next()) {
            double maximo = vie.value(0).toDouble();
            double promedio = vie.value(1).toDouble();
            double minimo = vie.value(2).toDouble();
            qDebug() << "Máximo:" << maximo << "Promedio:" << promedio << "Mínimo:" << minimo;
        }
    }
    for (int m = 0; m < 3; ++m) {
        R(0,m) = query.value(m).toDouble();
        R(1,m) = temp.value(m).toDouble();
        R(2, m) = luz.value(m).toDouble();
        R(3,m) = prec.value(m).toDouble();
        R(4,m) = vel.value(m).toDouble();
        R(5,m) = vel.value(m).toDouble();}
    db.close(); // Cierra la conexión

    return R;
}

void MainWindow::actualizarCadaMinuto()
{
    // construir matriz de interfaz
    MatrixXd R(6, 3);

    R = abrir_db();

    //TEMPERATURA
    QPalette palT = ui->ledT->palette();
    QPalette palH = ui->ledH->palette();
    ui->Tmin->setText(QString::number(R(1, 2)));
    ui->Tprom->setText(QString::number(R(1, 1)));
    ui->Tmax->setText(QString::number(R(1, 0)));
    ui->Tmin->setAlignment(Qt::AlignCenter);
    ui->Tprom->setAlignment(Qt::AlignCenter);
    ui->Tmax->setAlignment(Qt::AlignCenter);
    QRect rectT(QPoint(), ui->ledT->size());
    QRegion region(rectT, QRegion::Ellipse);
    ui->ledT->setMask(region);
    QString color;
    if (R(1, 0) == 45 || R(1, 0) == -10)
    {
        color = "red";
        ui->ledT->setText("¡Peligro!");
    }
    else if (R(1, 1) < -5 || R(1, 1) > 40)
    {
        color = "orange";
        ui->ledT->setText("Precaución");
    }
    else
    {
        color = "green";
        ui->ledT->setText("Estable");
    }
    ui->ledT->setAlignment(Qt::AlignCenter);

    // Aplicar el color al QLineEdit
    QString styleSheetT = QString("QLineEdit { background-color: %1; }").arg(color);
    ui->ledT->setStyleSheet(styleSheetT);

    //HuMEDAD
    ui->Hmin->setText(QString::number(R(0, 2)));
    ui->Hprom->setText(QString::number(R(0, 1)));
    ui->Hmax->setText(QString::number(R(0, 0)));
    ui->Hmin->setAlignment(Qt::AlignCenter);
    ui->Hprom->setAlignment(Qt::AlignCenter);
    ui->Hmax->setAlignment(Qt::AlignCenter);
    QRect rectH(QPoint(), ui->ledH->size());
    QRegion ledH(rectH, QRegion::Ellipse);
    ui->ledH->setMask(region);
    if (R(0, 1) == 100 || R(0, 1) == 0)
    {
        color = "red";
        ui->ledH->setText("¡Peligro!");
    }
    else if (R(0, 1) < 10 || R(0, 1) > 90)
    {
        color = "orange";
        ui->ledH->setText("Precaución");
    }
    else
    {
        color = "green";
        ui->ledH->setText("Estable");
    }
    ui->ledH->setAlignment(Qt::AlignCenter);

    // Aplicar el color al QLineEdit
    QString styleSheetH = QString("QLineEdit { background-color: %1; }").arg(color);
    ui->ledH->setStyleSheet(styleSheetH);

    //velocidad
    ui->Vmin->setText(QString::number(R(4, 2)));
    ui->Vprom->setText(QString::number(R(4, 1)));
    ui->Vmax->setText(QString::number(R(4, 0)));

    ui->Vmin->setAlignment(Qt::AlignCenter);
    ui->Vprom->setAlignment(Qt::AlignCenter);
    ui->Vmax->setAlignment(Qt::AlignCenter);

    //viento
    ui->Dmin->setText(QString::number(R(5, 2)));
    ui->Dprom->setText(QString::number(R(5, 1)));
    ui->Dmax->setText(QString::number(R(5, 0)));

    ui->Dmin->setAlignment(Qt::AlignCenter);
    ui->Dprom->setAlignment(Qt::AlignCenter);
    ui->Dmax->setAlignment(Qt::AlignCenter);

    ui->Pmin->setText(QString::number(R(3, 2)));
    ui->Pprom->setText(QString::number(R(3, 1)));
    ui->Pmax->setText(QString::number(R(3, 0)));

    // precipitación
    ui->Pmin->setAlignment(Qt::AlignCenter);
    ui->Pprom->setAlignment(Qt::AlignCenter);
    ui->Pmax->setAlignment(Qt::AlignCenter);

    //luz
    ui->Lmin->setText(QString::number(R(2, 2)));
    ui->Lprom->setText(QString::number(R(2, 1)));
    ui->Lmax->setText(QString::number(R(2, 0)));

    ui->Lmin->setAlignment(Qt::AlignCenter);
    ui->Lprom->setAlignment(Qt::AlignCenter);
    ui->Lmax->setAlignment(Qt::AlignCenter);
}
