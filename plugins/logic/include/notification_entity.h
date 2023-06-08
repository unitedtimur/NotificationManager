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
        explicit NotificationEntity(const QString &title,
                                    const QString &message,
                                    uint16_t type,
                                    const QString &color);
    };
}

#endif // NOTIFICATION_ENTITY_H
