#include "interface.h"

#include <QDebug>

bool GuiPluginTest::init()
{
    qDebug() << "Interface plugin";
    return true;
}
