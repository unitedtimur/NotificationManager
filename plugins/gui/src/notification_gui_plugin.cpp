#include "notification_gui_plugin.h"

#include <QDebug>

namespace GuiPlugin {
    bool NotificationGuiPlugin::initialize(const QList<QPointer<QObject>> &dependencies)
    {
        if (Core::AbstractCore::findPlugins(dependencies, _logicPlugin)) {
            qDebug() << Q_FUNC_INFO << "Plugin dependencies found";
            return true;
        } else {
            qWarning() << Q_FUNC_INFO << "Plugin dependencies not found";
            return false;
        }
    }
}
