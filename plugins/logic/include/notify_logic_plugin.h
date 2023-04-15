#ifndef NOTIFY_LOGIC_PLUGIN_H
#define NOTIFY_LOGIC_PLUGIN_H

#include "logic_interface.h"

#include <QString>
#include <QTimer>
#include <QObject>

namespace NMLogicPlugin {
    /*
         Класс реализующий плагин бизнес-логики отображения уведомлений
       */
    class NotificationLogicPlugin : public NMCore::LogicInterface
    {
        Q_OBJECT
        /*
                 Q_INTERFACES Этот макрос сообщает Qt, какие интерфейсы реализует класс. Это
               используется при внедрении плагинов.
                */
        Q_INTERFACES(NMCore::LogicInterface)
        /*
                Q_PLUGIN_METADATA  Этот макрос используется для объявления метаданных, которые
           являются частью плагина, создающего экземпляр этого объекта. Макрос должен объявить IID
               интерфейса, реализованного через объект, и сослаться на файл, содержащий метаданные
           для плагина.
                */
        Q_PLUGIN_METADATA(IID "com.NM.Core.LogicInterface" FILE "plugin_metadata.json")

        // Q_PROPERTY?
    public:
        virtual bool initialize() override;
    };
}

#endif // NOTIFY_LOGIC_PLUGIN_H
