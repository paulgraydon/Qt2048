#include "qtile.h"
#include <QString>
#include <QDebug>

#include "game.h"

Qtile::Qtile(QObject *parent) : QObject(parent)
{
    currentGame = new Game;
}

void Qtile::toStringCpp()
{
    compteur++;
    text = "Vous avez appuyé : "+QString::number(compteur,'f',0)+" fois sur le bouton";
    emit changementCPP(text);
    //qDebug() << "Hello World!";
}

void Qtile::restartGame()
{
    currentGame->restartGame();
    gameIsWon = false;
    gameIsOver = false;
    emit ChangeWinStatus();
    emit ChangeOverStatus();
}

QString Qtile::readValue(int index)
{
    QString qValue = currentGame->getGameBoard()->getTileValue(index);
    return (qValue);
}


QColor Qtile::readColor(int index)
{
    int valueForColor = currentGame->getGameBoard()->getTileValueForColor(index);
    QColor color;
    switch(valueForColor)
    {
        case 0: color = "#ccc0b2"; break;
        case 2: color = "#F4ECE4"; break;
        case 4: color = "#ece0c8"; break;
        case 8: color = "#f2b179"; break;
        case 16: color = "#f59563"; break;
        case 32: color = "#f57c5f"; break;
        case 64: color = "#f95c3b"; break;
        case 128: color = "#edce71"; break;
        case 256: color = "#eecc61"; break;
        case 512: color = "#ebc850"; break;
        case 1024: color = "#edc53f"; break;
        case 2048: color = "#eec22e"; break;
        case 4096: color = "#3d3a33"; break;
        case 8192: color = "#3d3a33"; break;
        case 16384: color = "#3d3a33"; break;
        default: color = "#ccc0b2"; break;
    }
    return color;
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
    gameIsWon = currentGame->isGameWon();
    if (gameIsWon) emit ChangeWinStatus();

    gameIsOver = currentGame->isGameOver();
    if (gameIsOver)
    {
        emit ChangeOverStatus();
    }
}


bool Qtile::GameIsWon()
{
    return gameIsWon;
}

bool Qtile::GameIsOver()
{
    return gameIsOver;
}
