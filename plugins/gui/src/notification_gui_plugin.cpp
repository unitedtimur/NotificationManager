#include "notification_gui_plugin.h"

#include <QDebug>

bool GuiPlugin::NotificationGuiPlugin::initialize(const QList<QPointer<QObject>> &dependencies)
{
    if (Core::AbstractCore::findPlugin<LogicPlugin::NotificationLogicPlugin>(_logicPlugin,
                                                                             dependencies)) {
        qDebug() << Q_FUNC_INFO << "Plugin dependencies found";
        return true;
    } else {
        qWarning() << Q_FUNC_INFO << "Plugin dependencies not found";
        return false;
    }
}
