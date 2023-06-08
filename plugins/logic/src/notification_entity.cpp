#include "notification_entity.h"

LogicPlugin::NotificationEntity::NotificationEntity(const QString &title,
                                                    const QString &message,
                                                    uint16_t type,
                                                    const QString &color) :
    AbstractNotification(title, message, type, color)
{}
