#ifndef DIVI_DIAG_H
#define DIVI_DIAG_H

#include <QDialog>

namespace Ui {
class Divi_diag;
}

class Divi_diag : public QDialog
{
    Q_OBJECT

public:
    explicit Divi_diag(QWidget *parent = nullptr);
    ~Divi_diag();

signals:
    void senalDivi(int tipo, double escalar);

private slots:
    void on_rdb_Ae_clicked();

    void on_rdb_Be_clicked();

    void on_rdb_AB_clicked();

    void on_rdb_BA_clicked();

    void on_buttonBox_accepted();

private:
    Ui::Divi_diag *ui;
};

#endif // DIVI_DIAG_H
