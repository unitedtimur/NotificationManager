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
        static AbstractCore &getInstance()
        {
            static AbstractCore core;
            return core;
        }

        /*!
         * \brief В методе реализована логика предоставления прямого доступа к каждому плагину,
         * лежащему в папке ../plugins. Указатели на root component каждого плагина добавляются в
         * список(QList<QPointer<QObject>> _plugins)
         * \param path - в этой строке находится путь до папки plugins
         */
        bool loadPlugins(const QString &path);

        /*!
         * \brief Метод присваивает переданному указателю адрес памяти, где находится плагин
         * \param _plugin - указатель внутри класса плагина
         * \param dependencies - плагины, среди которых нужно искать
         * \return True если плагин найден, иначе false
         */
        template<typename Interface>
        bool resolve(const QList<QPointer<QObject>> &objects, QPointer<Interface> &iface)
        {
            for (QPointer<QObject> object : objects)
                if (iface = qobject_cast<Interface *>(object); iface)
                    return true;

            return false;
        }

        template<typename T, typename... R>
        bool resolve(const QList<QPointer<QObject>> &dependencies, T *&plugin, R *&...plugins)
        {
            return resolve(dependencies, plugin) && resolve(dependencies, plugins...);
        }

    private:
        /*!
         * \brief Реализация патерна Singleton
         */
        explicit AbstractCore() = default;
        ~AbstractCore() = default;
        AbstractCore(const AbstractCore &) = delete;
        AbstractCore &operator=(AbstractCore) = delete;

        /*!
         * \brief Список плагинов, которые будут загружены из папки plugins
         */
        QList<QPointer<QObject>> _plugins;

        /*!
         * \brief Указатель на QSettings
         */
        QPointer<QSettings> _settings;
    };
}

#endif // ICORE_H
