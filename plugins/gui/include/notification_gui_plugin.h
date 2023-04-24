#ifndef NOTIFY_GUI_PLUGIN_H
#define NOTIFY_GUI_PLUGIN_H

#include "gui_interface.h"
#include "gui_plugin_export.h"
#include "notification_logic_plugin.h"

#include <QObject>
#include <QString>
#include <QTimer>

namespace GuiPlugin {
    /*!
     * \brief Класс реализующий плагин бизнес-логики отображения уведомлений
     */
    class GUI_PLUGIN_EXPORT NotificationGuiPlugin : public Core::GuiInterface
    {
        Q_OBJECT

        /*!
         * \brief Q_INTERFACES Этот макрос сообщает Qt, какие интерфейсы реализует класс. Это
         * используется при внедрении плагинов.
         */
        Q_INTERFACES(Core::GuiInterface)

        /*!
         * \brief Q_PLUGIN_METADATA  Этот макрос используется для объявления метаданных, которые
         * являются частью плагина, создающего экземпляр этого объекта. Макрос должен объявить IID
         * интерфейса, реализованного через объект, и сослаться на файл, содержащий метаданные для
         * плагина.
         */
        Q_PLUGIN_METADATA(IID "com.NotificationGuiPlugin" FILE "metadata.json")

        /*!
         * \brief Указатель на NotificationLogicPlugin
         */
        QPointer<LogicPlugin::NotificationLogicPlugin> notificationLogicPlugin;

    public:
        bool initialize(const QList<QPointer<QObject>> &dependencies) override;
    };
}
#endif // NOTIFY_GUI_PLUGIN_H
