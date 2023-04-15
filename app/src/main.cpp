#include "abstract_core.h"

#include <iostream>
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    std::cout << "app started" << std::endl;
    //    qputenv("QT_DEBUG_PLUGINS", QByteArray("1"));

    QApplication app(argc, argv);

    QString dir(QDir::currentPath());
    QDir thisDir(dir);
    thisDir.cdUp();
    thisDir.cd("plugins");

    QString plugDir = thisDir.absolutePath();

    NMCore::AbstractCore core;
    core.loadPlugins(plugDir);

    return app.exec();
}
