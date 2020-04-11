#ifndef QTILE_H
#define QTILE_H

#include <QObject>
#include <QDebug>
#include <QString>

#include "tile.h"



class Qtile: public QObject
{

    Q_OBJECT

public:
    explicit Qtile(QObject *parent = nullptr);

    //Q_INVOKABLE void toStringCpp();


signals:
    void changementCPP(QString text);

public slots:
    void toStringCpp();

private:
    QString text;
    int compteur = 0;

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
