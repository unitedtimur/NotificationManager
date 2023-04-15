#ifndef NOTIFY_LOGIC_PLUGIN_H
#define NOTIFY_LOGIC_PLUGIN_H

#include "gui_interface.h"

#include <QObject>
#include <QString>
#include <QTimer>
namespace NMGuiPlugin {
    /*!
     * \brief Класс реализующий плагин бизнес-логики отображения уведомлений
     */
    class GuiPlugin final : public NMCore::GuiInterface
    {
        Q_OBJECT
        /*!
         * \brief Q_INTERFACES Этот макрос сообщает Qt, какие интерфейсы реализует класс. Это
         * используется при внедрении плагинов.
         */
        Q_INTERFACES(NMCore::GuiInterface)
        /*!
         * \brief Q_PLUGIN_METADATA  Этот макрос используется для объявления метаданных, которые
         * являются частью плагина, создающего экземпляр этого объекта. Макрос должен объявить IID
         * интерфейса, реализованного через объект, и сослаться на файл, содержащий метаданные для
         * плагина.
         */
        Q_PLUGIN_METADATA(IID "com.NM.GuiPlugin." FILE "plugin_metadata.json")

    public:
        virtual bool initialize() override;
    };
}

#endif // NOTIFY_LOGIC_PLUGIN_H
