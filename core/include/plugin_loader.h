#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include "abstract_core.h"

#include <QDir>

namespace Core {
    /*!
     * \brief Класс, используемый для создания сущности, при помощи которой вызывается метод
     * загрузки плагинов
     */
    class PluginLoader
    {
    public:
        PluginLoader();
        ~PluginLoader() = default;

        /*!
         * \brief Метод, вызывающий метод загрузки плагинов
         * \param pluginsDir - переменная, указывающая на каталог с плагинами
         */
        void invokePluginsLoading(QDir pluginsDir);

    private:
        Core::AbstractCore _core;
        QString _pluginsDir;
    };
}
#endif // PLUGINLOADER_H
