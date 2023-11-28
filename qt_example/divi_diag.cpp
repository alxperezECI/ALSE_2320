#include "divi_diag.h"
#include "ui_divi_diag.h"

Divi_diag::Divi_diag(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Divi_diag)
{
    ui->setupUi(this);
}

Divi_diag::~Divi_diag()
{
    delete ui;
}



void Divi_diag::on_rdb_Ae_clicked()
{
    ui->gb_Escalar->setEnabled( true );
}

void Divi_diag::on_rdb_Be_clicked()
{
    ui->gb_Escalar->setEnabled( true );
}

void Divi_diag::on_rdb_AB_clicked()
{
    ui->gb_Escalar->setEnabled( false );
}

void Divi_diag::on_rdb_BA_clicked()
{
    ui->gb_Escalar->setEnabled( false );
}



void Divi_diag::on_buttonBox_accepted()
{
    double esc = ui->txt_Escalar->text().toDouble();
    int tipo = 0;

    if (ui->rdb_BA->isChecked()) tipo = 1;
    if (ui->rdb_Ae->isChecked()) tipo = 2;
    if (ui->rdb_Be->isChecked()) tipo = 3;

    emit senalDivi(tipo, esc);
}
