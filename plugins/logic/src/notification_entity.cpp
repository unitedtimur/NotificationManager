#include "notification_entity.h"

LogicPlugin::NotificationEntity::NotificationEntity(const QString &title,
                                                    const QString &description,
                                                    uint16_t type,
                                                    const QString &color) :
    AbstractNotification(title, description, type, color)
{}
