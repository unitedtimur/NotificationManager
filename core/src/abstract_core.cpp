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

        if (dir.exists())
#ifdef Q_OS_WIN
            plugins = dir.entryList(QStringList("*.dll"), QDir::Files);
#elif defined Q_OS_UNIX
            plugins = dir.entryList(QStringList("*.so"), QDir::Files);
#endif

        for (const auto &plugin : qAsConst(plugins)) {
            QPluginLoader loader(dir.absoluteFilePath(plugin));

            QObject *obj = qobject_cast<QObject *>(loader.instance());

            if (obj) {
                qDebug() << "Plugin loaded";
            } else {
                qWarning() << loader.errorString();
            }

            if (const auto plugin = qobject_cast<BaseInterface *>(obj); plugin) {
                _plugins.push_back(plugin);
            }
        }

        //        const auto excludePlugin = [this](auto excludedPlugin, auto plugins) {
        //            QList<QPointer<QObject>> result;

        //            for (const auto &plugin : plugins) {
        //                if (plugin != excludedPlugin) {
        //                    result.append(plugin);
        //                }
        //            }

        //            return result;
        //        };
    }

    QPointer<QQmlApplicationEngine> AbstractCore::qmlEngine() const
    {
        return _qmlEngine;
    }

} // namespace Core
