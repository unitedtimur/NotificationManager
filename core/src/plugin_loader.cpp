#include "plugin_loader.h"

Core::PluginLoader::PluginLoader()
{}

void Core::PluginLoader::invokePluginsLoading(QDir pluginsDir)
{
    _pluginsDir = pluginsDir.absolutePath();
    _core.loadPlugins(_pluginsDir);
}
