#include "qtile.h"
#include <QString>
#include <QDebug>

Qtile::Qtile(QObject *parent) : QObject(parent)
{

}


void Qtile::toStringCpp()
{
<<<<<<< HEAD
    compteur++;
    text = "Vous avez appuyé : "+QString::number(compteur,'f',0)+" fois sur le bouton";
    emit changementCPP(text);
=======
    qDebug() << "Hello World!";
>>>>>>> 527f5acfbe848ef762d29485a340a2c4e3e68f35
}
