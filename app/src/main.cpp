#include "abstract_core.h"

#include <iostream>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    std::cout << "app started" << std::endl;
    QCoreApplication app(argc, argv);

    QString dir(QDir::currentPath());
    QDir thisDir(dir);
    thisDir.cdUp();
    thisDir.cd("plugins");

    QString plugDir = thisDir.absolutePath();

    Core::AbstractCore core;
    core.loadPlugins(plugDir);

    return app.exec();
}
