#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_radioButton_clicked()
{
    ui->lineEdit->setEnabled(false);
}


void Dialog::on_radioButton_2_clicked()
{
    ui->lineEdit->setEnabled(false);
}


void Dialog::on_radioButton_3_clicked()
{
    ui->lineEdit->setEnabled(true);
}


void Dialog::on_radioButton_4_clicked()
{
    ui->lineEdit->setEnabled(true);
}


void Dialog::on_buttonBox_accepted()
{
    double esc = ui->lineEdit->text().toDouble();
    int tipo = 0;
    if (ui->radioButton_2->isChecked()) tipo = 1;
    if (ui->radioButton_3->isChecked()) tipo = 2;
    if (ui->radioButton_4->isChecked()) tipo = 3;

    emit senalDivi(tipo, esc);
}

