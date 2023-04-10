#pragma once
#include <iostream>
#include <QString>
#include <QDir>
#include <QPluginLoader>
#include <QMetaClassInfo>
#include <QCoreApplication>
#include "base_interface.h"
namespace Core {
    void init();
    void loadPlugins();
}
