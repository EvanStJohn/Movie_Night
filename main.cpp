#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "movie.h"
#include <QQuickWindow>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QObject *topLevel = engine.rootObjects().at(0);
        QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);

    Movie myClass;
            QObject::connect(window, SIGNAL(qmlSignal(QString)),
                             &myClass, SLOT(getMovie(QString)));

            QObject::connect(&myClass,
                             SIGNAL(setMovie(QVariant)),
                             window,
                             SLOT(updateText(QVariant)));

    return app.exec();
}
