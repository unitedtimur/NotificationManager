#include <plugin_loader.h>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QFile>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QString dir(QDir::currentPath());
    QDir thisDir(dir);
    thisDir.cdUp();
    thisDir.cd("plugins");
    Core::PluginLoader pluginInvoker;
    pluginInvoker.invokePluginsLoading(thisDir);
    return app.exec();
}
