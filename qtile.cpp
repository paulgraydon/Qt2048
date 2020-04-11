#include "qtile.h"
#include <QString>
#include <QDebug>

Qtile::Qtile(QObject *parent) : QObject(parent)
{

}


void Qtile::toStringCpp()
{
    qDebug() << "Hello World!";
}
