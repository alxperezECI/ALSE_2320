#ifndef VANTANA_H
#define VANTANA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class vantana; }
QT_END_NAMESPACE

class vantana : public QMainWindow
{
    Q_OBJECT

public:
    vantana(QWidget *parent = nullptr);
    ~vantana();

public slots:
    void tipoDivi(int tipo, double esc);

private slots:
    void on_cmd_Operacion_clicked();

private:
    Ui::vantana *ui;
    int     _tipoDivision;
    double  _escalar;
};
#endif // VANTANA_H
