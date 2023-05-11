#include "notification_entity.h"

LogicPlugin::NotificationEntity::NotificationEntity(QString title,
                                                    QString description,
                                                    uint16_t type) :
    AbstractNotification(title, description, type)
{}
