#ifndef NOTIFY_LOGIC_PLUGIN_H
#define NOTIFY_LOGIC_PLUGIN_H

#include "logic_interface.h"
#include "logic_plugin_export.h"

#include <QString>
#include <QTimer>
#include <QObject>

namespace LogicPlugin {
    /*!
     * \brief Класс реализующий плагин бизнес-логики отображения уведомлений
     */
    class LOGIC_PLUGIN_EXPORT NotificationLogicPlugin final : public Core::LogicInterface
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

#endif // NOTIFY_LOGIC_PLUGIN_H
