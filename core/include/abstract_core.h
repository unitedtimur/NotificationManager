#ifndef ABSTRACT_CORE_H
#define ABSTRACT_CORE_H

#include "core_export.h"
#include "base_interface.h"

#include <QDir>
#include <QObject>
#include <QPluginLoader>
#include <QPointer>
#include <QSettings>
#include <QQmlApplicationEngine>

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

#endif // ICORE_H
