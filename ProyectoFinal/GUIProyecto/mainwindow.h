#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
void changeLedColor(int tem,int hum);
static int callback( void *data, int argc, char **argv, char **azColName);
void update_measurements();

private slots:
void on_Measure_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
