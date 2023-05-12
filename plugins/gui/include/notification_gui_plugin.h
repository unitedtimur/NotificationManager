#ifndef NOTIFICATION_GUI_PLUGIN_H
#define NOTIFICATION_GUI_PLUGIN_H

#include "gui_plugin_export.h"
#include "gui_interface.h"

#include "abstract_core.h"
#include "notification_logic_plugin.h"

#include <QObject>
#include <QString>
#include <QtQuick>
#include <QQuickWindow>
#include <QQmlContext>
#include <QQmlApplicationEngine>
namespace GuiPlugin {
    /*!
     * \brief Класс реализующий плагин бизнес-логики отображения уведомлений
     */
    class GUI_PLUGIN_EXPORT NotificationGuiPlugin final : public Core::GuiInterface
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

    public:
        void invoke();
        void calculateLayout();
        void setupConnections();
        bool initialize(const QList<QPointer<QObject>> &dependencies) override;
        void setNotifyModel(LogicPlugin::NotificationModel *);
        void setHistoryModel(LogicPlugin::HistoryModel *);

    private:
         /*!
         * \brief Указатель на NotificationLogicPlugin
         */
        LogicPlugin::NotificationLogicPlugin *_logicPlugin { nullptr };
        LogicPlugin::NotificationModel *_notify_model { nullptr };
        LogicPlugin::HistoryModel *_history_model { nullptr };

        QList<QQuickWindow *> _notify_windows_list;
        Core::AbstractCore &_core = Core::AbstractCore::getInstance();

        void onRowsInserted(const QModelIndex &parent, int first, int last);
        void connectOnVisibleChanged(QQuickWindow *);

        /*!
         * \brief Указатель на движок QML
         */
        QQmlApplicationEngine _qmlEngine;

        int _screenHeight { 0 };
    };
}
#endif // NOTIFICATION_GUI_PLUGIN_H
