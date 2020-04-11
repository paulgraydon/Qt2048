#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "game.h"
#include "qtile.h"


int main(int argc, char *argv[])
{
    Game game;
    Board* gameBoard = game.getGameBoard();

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    Qtile aQtile;

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
