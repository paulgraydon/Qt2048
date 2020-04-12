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

void Qtile::performMove(int direction)
{
    qDebug()<< "Je bouge";
    qDebug()<< direction;
    if (direction == 1){
        currentGame->move(UP);
    }
    if (direction == 2){
        currentGame->move(DOWN);
    }
    if (direction == 3){
        currentGame->move(LEFT);
    }
    if (direction == 4){
        currentGame->move(RIGHT);
    }
    qDebug()<< "Je bouge";
    qDebug()<< direction;
}
