#include "notification_entity.h"

LogicPlugin::NotificationEntity::NotificationEntity(const QString &title,
                                                    const QString &description,
                                                    uint16_t type) :
    AbstractNotification(title, description, type)
{}
