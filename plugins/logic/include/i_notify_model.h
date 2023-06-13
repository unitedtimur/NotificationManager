#ifndef I_NOTIFY_MODEL_H
#define I_NOTIFY_MODEL_H

#include "logic_plugin_export.h"
#include "abstract_notification.h"

#include <QPointer>

namespace LogicPlugin {
    /*!
     * \brief INotifyModel - интерфейс для модели, используемой для передачи данных из плюсов в qml
     */
    class LOGIC_PLUGIN_EXPORT INotifyModel
    {
    public:
        virtual void createNotification(uint16_t typeID) = 0;
        virtual void addNotification(QPointer<LogicPlugin::AbstractNotification> notification) = 0;
        virtual void removeNotification(uint16_t id) = 0;
        virtual void clearNotifications() = 0;
        virtual int count() const = 0;
        virtual void reset() = 0;
    };
}
#endif // I_NOTIFY_MODEL_H
