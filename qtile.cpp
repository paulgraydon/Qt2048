#include "qtile.h"
#include <QString>
#include <QDebug>

Qtile::Qtile(QObject *parent) : QObject(parent)
{

}

void Qtile::toStringCpp()
{
    compteur++;
    text = "Vous avez appuyé : "+QString::number(compteur,'f',0)+" fois sur le bouton";
    emit changementCPP(text);
    //qDebug() << "Hello World!";
}

QString Qtile::readValue(int index)
{
    QString qValue = currentGame->getGameBoard()->getTileValue(index);
    return (qValue);
}

void Qtile::performMove(Direction dir)
{
    currentGame->move(dir);
}
