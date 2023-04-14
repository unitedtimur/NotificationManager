#include "interface.h"

#include <QDebug>

GuiPlugin::GuiPlugin(QObject *parent) : QObject(parent)
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

bool GuiPlugin::printDocument(QString strDoc)
{
    qDebug() << name() << "print:" << strDoc;
    return true;
}
