#ifndef QTILE_H
#define QTILE_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QColor>

#include "game.h"
#include "board.h"
#include "tile.h"

class Qtile: public QObject
{
    Q_OBJECT

    bool gameIsWon;
    bool gameIsOver;
    Q_PROPERTY(bool gameIsWon READ GameIsWon NOTIFY ChangeWinStatus)
    Q_PROPERTY(bool gameIsOver READ GameIsOver NOTIFY ChangeOverStatus)

public:
    explicit Qtile(QObject *parent = nullptr);

    //Q_INVOKABLE void toStringCpp();
    void setCurrentGame(Game* newGame) {currentGame = newGame;}
    Q_INVOKABLE void restartGame();
    Q_INVOKABLE QString readValue(int index);
    Q_INVOKABLE void performMove(int direction);
    Q_INVOKABLE QColor readColor(int index);

signals:
    void changementCPP(QString text);
    void ChangeWinStatus();
    void ChangeOverStatus();

public slots:
    void toStringCpp();

private:
    QString text;
    int compteur = 0;
    Game* currentGame;

//signals:

//public slots:

/*public:
    explicit Qtile(QObject *parent = nullptr);

    //Q_PROPERTY(QColor color MEMBER color NOTIFY colorValue)
    Q_PROPERTY(QString value MEMBER value NOTIFY getvalue)

signals:
    //void colorchoice();
    int getvalue();

private:
    Tile* tileassociee;
    //QColor color;
    int value;*/ 

};

#endif // QTILE_H
