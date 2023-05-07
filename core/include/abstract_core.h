#ifndef ICORE_H
#define ICORE_H

#include "core_export.h"

#include <QDir>
#include <QObject>
#include <QPluginLoader>
#include <QPointer>
#include <QSettings>
#include <QQmlApplicationEngine>

namespace Core {
    /*!
     * \brief Класс для загрузки плагинов и подготовки их к использованию
     */
    class CORE_EXPORT AbstractCore : public QObject
    {
        Q_OBJECT

    public:
        static AbstractCore *getInstance()
        {
            if (!p_instance)
                p_instance = new AbstractCore();
            return p_instance;
        }

        /*!
         * \brief В методе реализована логика предоставления прямого доступа к каждому плагину,
         * лежащему в папке ../plugins. Указатели на root component каждого плагина добавляются в
         * список(QList<QPointer<QObject>> _plugins)
         * \param path - в этой строке находится путь до папки plugins
         */
        bool loadPlugins(const QString &path);

        /*!
         * \brief Возвращает указатель на QQmlApplicationEngine
         */
        QPointer<QQmlApplicationEngine> qmlEngine() const;

        /*!
         * \brief Метод присваивает переданному указателю адрес памяти, где находится плагин
         * \param _plugin - указатель внутри класса плагина
         * \param dependencies - плагины, среди которых нужно искать
         * \return True если плагин найден, иначе false
         */
        template<typename T>
        bool findPlugins(const QList<QPointer<QObject>> &dependencies, T *&plugin)
        {
            for (const auto &dependency : qAsConst(dependencies)) {
                plugin = qobject_cast<T *>(dependency);

                if (plugin) {
                    return true;
                }
            }

            return false;
        }

        template<typename T, typename... R>
        bool findPlugins(const QList<QPointer<QObject>> &dependencies, T *&plugin, R *&...plugins)
        {
            return findPlugins(dependencies, plugin) && findPlugins(dependencies, plugins...);
        }

    private:
        /*!
         * \brief Реализация патерна Singleton
         */
        static AbstractCore *p_instance;
        AbstractCore();
        AbstractCore(const AbstractCore &);
        AbstractCore &operator=(AbstractCore &);

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
