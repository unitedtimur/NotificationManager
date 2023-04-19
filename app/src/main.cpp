#include "application.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QFile>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QString pluginsDir = QGuiApplication::applicationDirPath().left(
                          QGuiApplication::applicationDirPath().lastIndexOf('/'))
                         + "/plugins"; // тут не получится написать как ты в примере указал, потому
                                       // что applicationDirPath возвращает путь до директории app,
                                       // а plugins лежит на одном уровне с app
    App::Application pluginInvoker;
    pluginInvoker.invokePluginsLoading(pluginsDir);
    return app.exec();
}
