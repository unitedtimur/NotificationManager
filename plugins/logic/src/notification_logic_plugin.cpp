#include "notification_logic_plugin.h"

#include <QDebug>

namespace LogicPlugin {
    bool NotificationLogicPlugin::initialize(const QList<QPointer<QObject>> &dependencies)
    {
        return true;
    }

    void NotificationLogicPlugin::addNotification(AbstractNotification *notification)
    {
        _notify_model.addNotification(notification);
    }

    NotificationModel* NotificationLogicPlugin::getNotificationModel()
    {
        return &_notify_model;
    }

    HistoryModel* NotificationLogicPlugin::getHistoryModel()
    {
        return &_history_model;
    }
}
