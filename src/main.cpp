#include <QUrl>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "lineinterpolator.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QCoreApplication::setApplicationName("QtQuick Mapview");

    qmlRegisterType<LineInterpolator>("com.mapview.interpolator", 1, 0, "Interpolator");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/Map.qml")));

    return app.exec();
}
