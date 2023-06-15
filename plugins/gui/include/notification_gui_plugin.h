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
        bool initialize(const QList<QPointer<QObject>> &dependencies) override;
        void setNotifyModel(LogicPlugin::NotificationModel *);
        void setHistoryModel(LogicPlugin::HistoryModel *);
        Q_INVOKABLE void setDisplayCorner(int32_t position);
        QQuickWindow *createWindow(const QString &path, int32_t ix);
        QQuickWindow *createWindow(QQmlComponent &component, int32_t ix);
        QObject *createObject(QQmlComponent &component, QObject *parent, int ix);
        QQmlContext *context(QObject *object) const;

    private:
        void calculateLayout();
        void setupConnections();
        void onRowsInserted(const QModelIndex &parent, int ix);
        void connectOnVisibleChanged(QQuickWindow *);

        Core::AbstractCore &_core = Core::AbstractCore::getInstance();
        QPointer<QQmlApplicationEngine> _qmlEngine = _core.engine();
        QPointer<LogicPlugin::NotificationLogicPlugin> _logicPlugin { nullptr };
        LogicPlugin::NotificationModel *_notify_model { nullptr };
        LogicPlugin::HistoryModel *_history_model { nullptr };
        QList<QQuickWindow *> _notify_windows_list;

        qreal _screenHeight { -1 };
        qreal _screenWidth { -1 };
        int32_t _windowWidth { -1 };
        qreal _x_start_position { -1 };
        qreal _y_start_position { -1 };
        qreal y_position { -1 };
        qreal x_position { -1 };
        int16_t direction_sign { -1 };
        qreal margin { 5 };
        enum Position
        {
            TOP_LEFT,
            TOP_RIGHT,
            BOTTOM_RIGHT,
            BOTTOM_LEFT
        };
    };
}
#endif // NOTIFICATION_GUI_PLUGIN_H
