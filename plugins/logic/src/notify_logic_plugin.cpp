#include "notify_logic_plugin.h"

#include <QDebug>

bool NMLogicPlugin::NotificationLogicPlugin::initialize()
{
    qDebug() << "Initialize";
    return true;
}
