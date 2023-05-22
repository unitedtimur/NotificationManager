#include "notification_logic_plugin.h"

#include <QDebug>

namespace LogicPlugin {
    bool NotificationLogicPlugin::initialize(const QList<QPointer<QObject>> &dependencies)
    {
        return true;
    }
}
