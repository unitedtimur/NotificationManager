#include "abstract_core.h"

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
            QPluginLoader pluginLoader(dir.absolutePath() + "/" + plugin);

            const auto pluginInterface = pluginLoader.instance();

            if (!pluginInterface) {
                qWarning() << "Unknow plugin in plugins folder";
                continue;
            }

            if (const auto plugin = qobject_cast<BaseInterface *>(pluginInterface); plugin) {
                _plugins.push_back(plugin);
            }
        }

        const auto excludePlugin = [this](auto excludedPlugin, auto plugins) {
            QList<QPointer<QObject>> result;

            for (const auto &plugin : plugins) {
                if (plugin != excludedPlugin) {
                    result.append(plugin);
                }
            }

            return result;
        };

        for (const auto &plugin : qAsConst(_plugins)) {
            auto *interface = qobject_cast<BaseInterface *>(plugin);
            const auto isLoaded = interface->initialize(excludePlugin(plugin, _plugins));

            if (!isLoaded) {
                qWarning() << "Failed to load plugin";
                _plugins = excludePlugin(plugin, _plugins);
            } else {
                qInfo() << "Plugin is loaded";
            }
        }
    }

    QPointer<QQmlApplicationEngine> CoreBasis::qmlEngine() const
    {
        return _qmlEngine;
    }

} // namespace Core
