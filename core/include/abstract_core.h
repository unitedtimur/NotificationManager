#ifndef ICORE_H
#define ICORE_H

#include "core_export.h"

#include <QDir>
#include <QObject>
#include <QPluginLoader>
#include <QPointer>
#include <QSettings>
#include <QQmlApplicationEngine>

namespace NMCore {
    class CORE_EXPORT AbstractCore : public QObject
    {
        Q_OBJECT

    public:
        explicit AbstractCore();

        void loadPlugins(const QString &path);

        QPointer<QQmlApplicationEngine> qmlEngine() const;

        // ...

    private:
        /*!
         * \brief Список плагинов, которые будут загружены из папки plugins
         */
        QList<QPointer<QObject>> _plugins;

        /*!
         * \brief Указатель на движок QML
         */
        QPointer<QQmlApplicationEngine> _qmlEngine;

        /*!
         * \brief Указатель на QSettings
         */
        QPointer<QSettings> _settings;
    };
}

#endif // ICORE_H
