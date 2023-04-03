#ifndef NOTIFY_LOGIC_PLUGIN_H
#define NOTIFY_LOGIC_PLUGIN_H
#include "logic_interface.h"
#include "notification_info.h"
#include <QString>
#include <QTimer>
namespace LogicPlugin {
    /*
         Класс реализующий плагин бизнес-логики отображения уведомлений
       */
    class NotificationLogicPlugin : public QObject, public Core::LogicInterface
    {
        Q_OBJECT
        /*
                 Q_INTERFACES Этот макрос сообщает Qt, какие интерфейсы реализует класс. Это
               используется при внедрении плагинов.
                */
        Q_INTERFACES(Core::LogicInterface)
        /*
                Q_PLUGIN_METADATA  Этот макрос используется для объявления метаданных, которые
           являются частью плагина, создающего экземпляр этого объекта. Макрос должен объявить IID
               интерфейса, реализованного через объект, и сослаться на файл, содержащий метаданные
           для плагина.
                */
        Q_PLUGIN_METADATA(IID "com.Core.LogicInterface" FILE "logic_interface.json")

        // Q_PROPERTY?
    public:
        NotificationLogicPlugin(QObject *parent);
        bool hasNotifications();
        void addNotification(NotificationInfo);
        void clearList();
        virtual bool initialize(const QList<QPointer<QObject>> &dependencies) override;

    private:
        /*
             _enabled - переменная отвечающая за вкл/выкл уведомлений
            */
        bool _enabled;
        /*
             _maxNotifyOnScreen - число максимально одновременно отображаемых уведомлений
            */
        int _maxNotificationsOnScreen;
        /*
             _countOfNotifications - текущее число одновременно отображаемых уведомлений
            */
        int _countOfNotifications = 0;
        /*
              _notify_list - список уведомлений
            */
        QList<LogicPlugin::NotificationInfo> _notify_list;
    public slots:
        void setEnabled(bool);
    private slots:
        void showNextNotification();
        void removeNotification();
    signals:
        void enabledChangedNotifications(bool);
        void showNotificationSignal(LogicPlugin::NotificationInfo);
        void removeNotificationSignal();
    };
}

#endif // NOTIFY_LOGIC_PLUGIN_H
