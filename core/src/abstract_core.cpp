#include "abstract_core.h"
#include "base_interface.h"

#include <iostream>
#include <QCoreApplication>

// #ifdef Q_OS_WIN
// #    include "windows.h"
// #endif

namespace Core {
    AbstractCore *AbstractCore::p_instance = 0;

    AbstractCore::AbstractCore()
    {
        _qmlEngine = new QQmlApplicationEngine(this);
    }

    bool AbstractCore::loadPlugins(const QString &path)
    {
        QStringList plugins;
        QDir dir(path);

        if (!dir.exists())
            return false;

#ifdef Q_OS_WIN
        plugins = dir.entryList(QStringList("*.dll"), QDir::Files);
//        SetDllDirectoryA((LPCSTR)path.toStdString().c_str());
#elif defined Q_OS_UNIX
        plugins = dir.entryList(QStringList("*.so"), QDir::Files);
#endif
        qDebug() << QCoreApplication::libraryPaths();
        for (const auto &plugin : qAsConst(plugins)) {
            QPluginLoader loader;
            loader.setFileName(path + "/" + plugin);

            const auto *loadingObject = qobject_cast<QObject *>(loader.instance());

            if (loadingObject) {
                qDebug() << Q_FUNC_INFO << "Plugin loaded";
            } else {
                qWarning() << Q_FUNC_INFO << loader.errorString();
                return false;
            }

            if (const auto plugin = qobject_cast<BaseInterface *>(loadingObject); plugin) {
                _plugins.push_back(plugin);
            }
        }

        for (const auto &plugin : qAsConst(_plugins)) {
            const auto p = qobject_cast<BaseInterface *>(plugin.data());
            if (!p->initialize(_plugins)) {
                qDebug() << Q_FUNC_INFO << "Initialize failed";
                return false;
            }
        }

        qDebug() << Q_FUNC_INFO << "Plugins loaded";

        return true;
    }

    QPointer<QQmlApplicationEngine> AbstractCore::qmlEngine() const
    {
        return _qmlEngine;
    }
} // namespace Core
