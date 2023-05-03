#ifndef NOTIFICATION_ENTITY_H
#define NOTIFICATION_ENTITY_H

#include "abstract_notification.h"

namespace LogicPlugin {
    /*!
     * \brief Имплементация класса, в который нужно вносить изменения, если это потребуется
     */
    class NotificationEntity final : public AbstractNotification
    {
    public:
        explicit NotificationEntity(QString title, QString description, uint16_t type);
    };
}

#endif // NOTIFICATION_ENTITY_H
