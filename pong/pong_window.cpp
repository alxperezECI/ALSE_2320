#include "pong_window.h"
#include "ui_pong_window.h"
#include <QTimer>

Pong_Window::Pong_Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pong_Window)
{
    ui->setupUi(this);
    _temporizador = new QTimer();
    _temporizador->setInterval( 50 );
    connect(_temporizador, SIGNAL(timeout()), this, SLOT(mover()) );

    _vx = _vy = 0.;
    _ux = 0.77;
    _uy = 0.55;
    _diametro = 40;
    ui->sld_diametro->setValue( _diametro );
    _x = _y = ui->cmd_boton->x();

    QRect rect(QPoint(), ui->cmd_boton->size());
    rect.adjust(5, 5, -5, -5);
    QRegion region(rect,QRegion::Ellipse);
    ui->cmd_boton->setMask(region);

    QPalette pal = ui->cmd_boton->palette();
    pal.setColor(QPalette::Button, QColor(Qt::red));
    ui->cmd_boton->setAutoFillBackground(true);
    ui->cmd_boton->setPalette(pal);
    ui->cmd_boton->update();

    _temporizador->start();
}

Pong_Window::~Pong_Window()
{
    delete ui;
    delete _temporizador;
}

void Pong_Window::on_cmd_boton_clicked()
{
    if( _temporizador->isActive() )
        _temporizador->stop();
    else
        _temporizador->start();
}

void Pong_Window::mover()
{
    QPoint pos = ui->cmd_boton->pos();
    pos.setX( pos.x() + _vx );
    pos.setY( pos.y() + _vy );

    if( pos.x() < 0 || pos.x() + _diametro > ui->centralWidget->width() ){
        _ux = -_ux;
        _vx = -_vx;
    }
    if( pos.y() < 0 || pos.y() + _diametro > ui->centralWidget->height() ){
        _uy = -_uy;
        _vy = -_vy;
    }

    pos = ui->cmd_boton->pos();
    pos.setX( pos.x() + _vx );
    pos.setY( pos.y() + _vy );

    ui->cmd_boton->move( pos );
}

void Pong_Window::on_sld_velocidad_valueChanged(int value)
{
    _vx = _ux * value;
    _vy = _uy * value;
}

void Pong_Window::on_sld_diametro_valueChanged(int value)
{
    QSize btnSize(value, value);

    QRect rect(QPoint(), btnSize );
    rect.adjust(5, 5, -5, -5);
    QRegion region(rect,QRegion::Ellipse);
    ui->cmd_boton->resize( btnSize );
    ui->cmd_boton->setMask( region );
}
