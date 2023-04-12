#include <core.h>

#include <iostream>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QFile>

int main(int argc, char *argv[])
{
    Core::init();

    QFile file(":/qml/main.qml");
    qDebug() << file.exists();

    return 0;
}
