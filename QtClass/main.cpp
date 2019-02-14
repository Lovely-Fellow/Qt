#include <QCoreApplication>
#include <QDebug>
#include "a.h"
#include "b.h"
#include "c.h"

int A::a = 0;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    B b;
    C c;

    b.set_val(10);
    qDebug() << c.get_val() <<endl;
    return a.exec();
}
