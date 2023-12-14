#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <eigen3/Eigen/Dense>
#include <QTimer>
#include <QtSql/QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE
using Eigen ::MatrixXd;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    MatrixXd abrir_db();

private slots:
    void actualizarCadaMinuto();

private:
    Ui::MainWindow *ui;
    QTimer *timer; // Objeto QTimer
    QSqlDatabase db;
};
#endif // MAINWINDOW_H
