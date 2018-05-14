#include <QUrl>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "lineinterpolator.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QCoreApplication::setApplicationName("QtQuick Mapview");

//     qmlRegisterType<LineInterpolator>("mapview.lineinterpolator", 1, 0, "LineInterpolator");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/Map.qml")));

    return app.exec();
}
