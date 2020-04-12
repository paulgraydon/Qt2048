#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <stdlib.h>
#include <time.h>

#include "game.h"
#include "board.h"
#include "tile.h"
#include "qtile.h"



int main(int argc, char *argv[])
{
    srand(time(NULL));

    Game game(4, 4);
    Game* gamePtr = &game;

    game.restartGame();

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    Qtile aQtile;
    aQtile.setCurrentGame(gamePtr);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.rootContext()->setContextProperty("vueObjetCpt",&aQtile);
    engine.load(url);

    return app.exec();
}
