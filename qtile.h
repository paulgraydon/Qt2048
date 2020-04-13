#ifndef QTILE_H
#define QTILE_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QColor>

#include "game.h"
#include "board.h"
#include "tile.h"

// Classe Qtile permettant de relier la partie logique du programme en C++ à l'affichage en QML
class Qtile: public QObject
{
    Q_OBJECT

    bool gameIsWon;
    bool gameIsOver;
    Q_PROPERTY(bool gameIsWon READ GameIsWon NOTIFY ChangeWinStatus)
    Q_PROPERTY(bool gameIsOver READ GameIsOver NOTIFY ChangeOverStatus)

public:
    explicit Qtile(QObject *parent = nullptr);

    void setCurrentGame(Game* newGame) {currentGame = newGame;}
    Q_INVOKABLE void restartGame();
    Q_INVOKABLE QString readValue(int index);
    Q_INVOKABLE void performMove(int direction);
    Q_INVOKABLE QColor readColor(int index);
    Q_INVOKABLE QString getScore();

    bool GameIsWon();
    bool GameIsOver();

signals:
    void ChangeWinStatus();
    void ChangeOverStatus();

private:
    QString text;
    Game* currentGame;

};

#endif // QTILE_H
