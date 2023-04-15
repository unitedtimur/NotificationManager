#include "interface.h"

#include <QDebug>

GuiPlugin::GuiPlugin(QObject *parent)
{
    qDebug() << name() << "created";
}

GuiPlugin::~GuiPlugin()
{
    qDebug() << name() << "destroyed";
}

QString GuiPlugin::name()
{
    return "Interface plugin";
}

bool GuiPlugin::printName()
{
    qDebug() << "Interface plugin";
    return true;
}
