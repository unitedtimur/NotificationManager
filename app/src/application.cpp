#include "application.h"

App::Application::Application()
{}

void App::Application::invokePluginsLoading(const QString &pluginsDir)
{
    _core->loadPlugins(pluginsDir);
}
