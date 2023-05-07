#ifndef APPLICATION_H
#define APPLICATION_H

#include <abstract_core.h>

#include <QDir>

namespace App {
    /*!
     * \brief Класс, используемый для создания сущности, при помощи которой вызывается метод
     * загрузки плагинов
     */
    class Application
    {
    public:
        explicit Application();
        ~Application() = default;

        /*!
         * \brief Метод, вызывающий метод загрузки плагинов
         * \param pluginsDir - переменная, указывающая на каталог с плагинами
         */
        void invokePluginsLoading(const QString &pluginsDir);

    private:
        /*!
         * \brief _core - объект класса AbstractCore, через него в методе invokePluginsLoading
         * вызываем метод loadPlugins, принадлежащий AbstractCore
         */
        Core::AbstractCore *_core = Core::AbstractCore::getInstance();
    };
}
#endif // APPLICATION_H
