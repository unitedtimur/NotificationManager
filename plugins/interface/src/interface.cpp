#include "interface.h"

#include <QDebug>

GuiPlugin::GuiPlugin(QObject *parent)
{
    qDebug() << "created";
}

GuiPlugin::~GuiPlugin()
{
    qDebug() << "destroyed";
}

bool GuiPlugin::printName()
{
    qDebug() << "Interface plugin";
    return true;
}
