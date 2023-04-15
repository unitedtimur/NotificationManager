#include "gui_plugin.h"

#include <QDebug>

bool NMGuiPlugin::GuiPlugin::initialize()
{
    qDebug() << "Initialize";
    return true;
}
