#include "application.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QFile>
#include <QtPlugin>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    app.setQuitOnLastWindowClosed(false);

    QString pluginsDir = QGuiApplication::applicationDirPath() + "/plugins";
    QCoreApplication::addLibraryPath(pluginsDir + "/logic");

    App::Application pluginInvoker;

    pluginInvoker.invokePluginsLoading(pluginsDir);
    app.exec();
}
