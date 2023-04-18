#include <abstract_core.h>

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

    QString plugDir = thisDir.absolutePath();

    Core::AbstractCore core;
    core.loadPlugins(plugDir);

    return app.exec();
}
