#ifndef NOTIFICATION_LOGIC_PLUGIN_H
#define NOTIFICATION_LOGIC_PLUGIN_H

#include "logic_interface.h"

#include <QString>
#include <QTimer>
#include <QObject>

namespace LogicPlugin {
    /*!
     * \brief Класс реализующий плагин бизнес-логики отображения уведомлений
     */
    class NotificationLogicPlugin : public Core::LogicInterface
    {
        Q_OBJECT
        /*!
         * \brief Q_INTERFACES Этот макрос сообщает Qt, какие интерфейсы реализует класс. Это
         * используется при внедрении плагинов.
         */
        Q_INTERFACES(Core::LogicInterface)

        /*!
         * \brief Q_PLUGIN_METADATA  Этот макрос используется для объявления метаданных, которые
         * являются частью плагина, создающего экземпляр этого объекта. Макрос должен объявить IID
         * интерфейса, реализованного через объект, и сослаться на файл, содержащий метаданные для
         * плагина.
         */
        Q_PLUGIN_METADATA(IID "com.Core.LogicInterface" FILE "metadata.json")

    public:
        bool initialize(const QList<QPointer<QObject>> &dependencies) override;
    };
}

#endif // NOTIFICATION_LOGIC_PLUGIN_H
