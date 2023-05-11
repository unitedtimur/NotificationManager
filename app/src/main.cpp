#include "application.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    app.setQuitOnLastWindowClosed(false);

    QString pluginsDir = QGuiApplication::applicationDirPath() + "/plugins";
    QCoreApplication::addLibraryPath(pluginsDir + "/logic");

    App::Application pluginInvoker;

    pluginInvoker.invokePluginsLoading(pluginsDir);
    app.exec();
}
