#include "gui_plugin.h"

#include <QDebug>

bool GuiPlugin::initialize()
{
    qDebug() << "Initialize";
    return true;
}
