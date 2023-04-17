#ifndef NOTIFICATION_ENTITY_H
#define NOTIFICATION_ENTITY_H

#include <abstract_notification.h>

namespace LogicPlugin {
    /*!
     * \brief Имплементация класса, в который нужно вносить изменения, если это потребуется
     */
    class notification_entity final : public AbstractNotification
    {
    public:
        notification_entity(QString title, QString description, int type);
    };
}

#endif // NOTIFICATION_ENTITY_H
