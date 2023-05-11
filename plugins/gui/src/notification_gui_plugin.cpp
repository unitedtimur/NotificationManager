#include "notification_gui_plugin.h"

#include <QDebug>

namespace GuiPlugin {
    bool NotificationGuiPlugin::initialize(const QList<QPointer<QObject>> &dependencies)
    {
        if (_core->findPlugins(dependencies, _logicPlugin)) {
            qDebug() << Q_FUNC_INFO << "Plugin dependencies found";
            show();
            return true;
        } else {
            qWarning() << Q_FUNC_INFO << "Plugin dependencies not found";
            return false;
        }
    }

    void NotificationGuiPlugin::show()
    {
        _core->qmlEngine()->load(QUrl(QStringLiteral("qrc:/qml/qml/main.qml")));
        _core->qmlEngine()->addImportPath("qrc:/qml");
        _core->qmlEngine()->load(QUrl(QStringLiteral("qrc:/qml/qml/listView.qml")));
    }
}
