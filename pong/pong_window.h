#ifndef PONG_WINDOW_H
#define PONG_WINDOW_H

#include <QMainWindow>

namespace Ui {
class Pong_Window;
}

class Pong_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pong_Window(QWidget *parent = 0);
    ~Pong_Window();

private slots:
    void on_cmd_boton_clicked();
    void mover();

    void on_sld_velocidad_valueChanged(int value);

    void on_sld_diametro_valueChanged(int value);

private:
    Ui::Pong_Window *ui;
    QTimer *_temporizador;
    int _x, _y;
    float _vx, _vy; // Velocidad en x y y.
    float _ux, _uy; // Vector unitario del movimiento
    int _diametro;
};

#endif // PONG_WINDOW_H
