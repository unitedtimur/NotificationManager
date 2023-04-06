#include <iostream>
#include "core.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "C:/Users/PC/Documents/qtProjects/NotificationManager/plugins/logic/include/notify_model.h"
#include <QQmlEngine>
#include <QQmlContext>
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    NotificationModel notificationModel;
    // Добавляем уведомление в модель
    notificationModel.addNotification("New notification1", "This is a new notification");
    notificationModel.addNotification("New notification2", "This is a new notification");
    notificationModel.addNotification("New notification", "This is a new notification");
    notificationModel.addNotification("New notification", "This is a new notification");
    notificationModel.addNotification("New notification", "This is a new notification");
    notificationModel.addNotification("New notification", "This is a new notification");
    notificationModel.addNotification("New notification", "This is a new notification");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    engine.rootContext()->setContextProperty("Notificationmodel", &notificationModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
