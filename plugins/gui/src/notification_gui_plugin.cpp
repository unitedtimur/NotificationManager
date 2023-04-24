#include "notification_gui_plugin.h"

#include <QDebug>

bool GuiPlugin::NotificationGuiPlugin::initialize(const QList<QPointer<QObject>> &dependencies)
{
    for (const auto &plugin : qAsConst(dependencies)) {
        if (const auto &nlp = qobject_cast<LogicPlugin::NotificationLogicPlugin *>(plugin.data());
            nlp) {
            notificationLogicPlugin = nlp;
        }
    }

    if (!notificationLogicPlugin)
        return false;

    return true;
}
