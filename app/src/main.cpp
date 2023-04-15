#include "abstract_core.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QFile>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    NMCore::AbstractCore core;
    core.loadPlugins("plugins");

    return app.exec();
}
