#include <iostream>
#include "core.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "notify_model.h"
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
    notificationModel.addNotification("Обнаружена цель в SportCenter", "Очень важная информация. Очень важная информация.", 0);
    notificationModel.addNotification("Камера не доступна!", "Очень важная информация. Очень важная информация.", 1);
    notificationModel.addNotification("Высокий уровень шума", "Очень важная информация. Очень важная информация.", 2);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("Notificationmodel", &notificationModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
