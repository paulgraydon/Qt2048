#ifndef QTILE_H
#define QTILE_H

#include <QObject>

#include "tile.h"



class Qtile: public QObject
{
public:
    explicit Qtile(QObject *parent = nullptr);

    //Q_PROPERTY(QColor color MEMBER color NOTIFY colorValue)
    //Q_PROPERTY(QString value MEMBER value NOTIFY getValue)

signals:
    //void colorValue();
    //int getValue();

private:
    //Tile* tileassociee;
    //QColor color;
    QString value;

};

#endif // QTILE_H
