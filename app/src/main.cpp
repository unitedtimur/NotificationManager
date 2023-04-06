#include <iostream>
#include "core.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "G:/Qt/repos/NotificationManager/plugins/logic/include/notify_model.h"
#include <QQmlEngine>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<NotificationModel>("com.example.notificationmodel", 1, 0, "notify_model");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
