#include "abstract_core.h"
#include "base_interface.h"

#include <iostream>

namespace Core {
    AbstractCore::AbstractCore()
    {
        _qmlEngine = new QQmlApplicationEngine(this);
    }

    void AbstractCore::loadPlugins(const QString &path)
    {
        QStringList plugins;
        QDir dir(path);

        if (!dir.exists())
            return;

#ifdef Q_OS_WIN
        plugins = dir.entryList(QStringList("*.dll"), QDir::Files);
#elif defined Q_OS_UNIX
        plugins = dir.entryList(QStringList("*.so"), QDir::Files);
#endif
        for (const auto &plugin : qAsConst(plugins)) {
            QPluginLoader loader;
            loader.setFileName(path + "/" + plugin);

            const auto *loadingObject = qobject_cast<QObject *>(loader.instance());

            if (loadingObject) {
                qDebug() << Q_FUNC_INFO << "Plugin loaded";
            } else {
                qWarning() << Q_FUNC_INFO << loader.errorString();
            }

            if (const auto plugin = qobject_cast<BaseInterface *>(loadingObject); plugin) {
                _plugins.push_back(plugin);
            }
        }
    }

    QPointer<QQmlApplicationEngine> AbstractCore::qmlEngine() const
    {
        return _qmlEngine;
    }
} // namespace Core
