#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ledindicator.h"
#include <sqlite3.h>
#include <string>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::changeLedColor(const int tem,const int hum) {
    QColor color;
    if (tem < 30) {
    color = Qt::green;
    } else if (tem >= 30 && tem < 43) {
        color = Qt::yellow;
    } else if (tem >= 43) {
        color = Qt::red;
    } else {
        color = Qt::black;
    }
    ui->led_temp->setColor(color);

    if (hum < 60) {
        color = Qt::green;
    } else if (hum >= 60 && hum < 85) {
        color = Qt::yellow;
    } else if (hum >= 85) {
        color = Qt::red;
    } else {
        color = Qt::black;
    }
    ui->led_hume->setColor(color);
}

int MainWindow::callback( void *data, int argc, char **argv, char **azColName){
    int* local=(int*)data;
    for(int i=0; i<argc; i++){
        local[i]=atoi(argv[i]);
    }
   return 0;
}

void MainWindow::update_measurements(){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    std::string sqlstr;
    int res[3];
    int humedad;
    rc = sqlite3_open("../../sensores.db", &db);
    if( rc != 0 ) {
      fprintf(stderr, "No se puede abrir la base de datos: %s\n", sqlite3_errmsg(db));
    } else {
        fprintf(stdout, "Se abrió correctamente la base de datos\n");
    }
    sqlstr="SELECT Promedio, Máximo, Mínimo FROM humedad ORDER BY Inde DESC LIMIT 1";
    rc = sqlite3_exec(db, sqlstr.c_str(), callback, (void*)&res, &zErrMsg);
        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        ui->LineHum->setText(QString::number(res[0]));
        ui->MaxHum->setText(QString::number(res[1]));
        ui->MinHum->setText(QString::number(res[2]));
        humedad=res[1];
        sqlstr="SELECT Promedio, Máximo, Mínimo FROM luz ORDER BY Inde DESC LIMIT 1";
        rc = sqlite3_exec(db, sqlstr.c_str(), callback, (void*)&res, &zErrMsg);
        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
        ui->LineLuz->setText(QString::number(res[0]));
        ui->MaxLuz->setText(QString::number(res[1]));
        ui->MinLuz->setText(QString::number(res[2]));
        sqlstr="SELECT Promedio, Máximo, Mínimo FROM temperatura ORDER BY Inde DESC LIMIT 1";
        rc = sqlite3_exec(db, sqlstr.c_str(), callback, (void*)&res, &zErrMsg);
        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        ui->LineTemp->setText(QString::number(res[0]));
        ui->MaxTemp->setText(QString::number(res[1]));
        ui->MinTemp->setText(QString::number(res[2]));
        MainWindow::changeLedColor(res[1],humedad);
        sqlstr="SELECT Promedio, Máximo, Mínimo FROM lluvia ORDER BY Inde DESC LIMIT 1";
        rc = sqlite3_exec(db, sqlstr.c_str(), callback, (void*)&res, &zErrMsg);
        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        ui->LineLluvia->setText(QString::number(res[0]));
        ui->MaxLluvia->setText(QString::number(res[1]));
        ui->MinLluvia->setText(QString::number(res[2]));
        sqlstr="SELECT Promedio, Máximo, Mínimo FROM viento ORDER BY Inde DESC LIMIT 1";
        rc = sqlite3_exec(db, sqlstr.c_str(), callback, (void*)&res, &zErrMsg);
        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } 
        ui->LineDirec->setText(QString::number(res[0]));
        ui->MaxDirec->setText(QString::number(res[1]));
        ui->MinDirec->setText(QString::number(res[2]));
        sqlstr="SELECT Promedio, Máximo, Mínimo FROM velocidad ORDER BY Inde DESC LIMIT 1";
        rc = sqlite3_exec(db, sqlstr.c_str(), callback, (void*)&res, &zErrMsg);
        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        ui->LineVel->setText(QString::number(res[0]));
        ui->MaxVel->setText(QString::number(res[1]));
        ui->MinVel->setText(QString::number(res[2]));
        sqlite3_close(db);
}
    
void MainWindow::on_Measure_clicked()
{
    update_measurements();
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::update_measurements);
    timer->start(60000);
}

