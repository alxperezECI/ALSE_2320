#include "vantana.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vantana w;
    w.show();
    return a.exec();
}
