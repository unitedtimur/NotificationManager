#include "application.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QFile>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
<<<<<<< HEAD
    QString pluginsDir = QGuiApplication::applicationDirPath().left(
                          QGuiApplication::applicationDirPath().lastIndexOf('/'))
                         + "/plugins";
    App::Application pluginInvoker;
    pluginInvoker.invokePluginsLoading(pluginsDir);
=======

    NMCore::AbstractCore core;
    core.loadPlugins("plugins");

>>>>>>> install-root
    return app.exec();
}
