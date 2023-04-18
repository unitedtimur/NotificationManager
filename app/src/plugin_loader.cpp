#include "plugin_loader.h"

App::PluginLoader::PluginLoader()
{}

void App::PluginLoader::invokePluginsLoading(QDir pluginsDir)
{
    _pluginsDir = pluginsDir.absolutePath();
    _core.loadPlugins(_pluginsDir);
}
