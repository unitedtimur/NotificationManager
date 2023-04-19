#include "application.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QFile>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    App::Application pluginInvoker;
    pluginInvoker.invokePluginsLoading("plugins");
    return app.exec();
}
