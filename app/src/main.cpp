#include "abstract_core.h"

#include <iostream>
#include <QCoreApplication>
#include <QFile>

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
//=======
//#include "core.h"
//#include <QGuiApplication>
//#include <QQmlApplicationEngine>
//#include <QQmlEngine>
//#include <QQmlContext>
//#include <QFile>

//int main(int argc, char *argv[])
//{
//    Core::init();

//    QFile file(":/qml/main.qml");
//    qDebug() << file.exists();

//    return 0;
//}
