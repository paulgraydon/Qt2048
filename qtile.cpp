#include "qtile.h"

Qtile::Qtile(QObject *parent) : QObject(parent)
{
}

int Qtile::getvalue()
{
    value = tileassociee->getValue();
    return value;

}
