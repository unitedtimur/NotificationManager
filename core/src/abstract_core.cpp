#include "core.h"
#include <iostream>

namespace Core {
    CoreBasis::CoreBasis()
    {
        std::cout << "Core init" << std::endl;
    }

    void CoreBasis::loadPlugins()
    {
#ifdef Q_OS_WIN64
        const auto pluginExtension = ".dll";
#elif defined(Q_OS_LINUX)
        const auto pluginExtension = ".so";
#endif
        QString parentDir(QDir::currentPath());
        QDir currentDir(parentDir);
        currentDir.cdUp();
        QString projectDir = currentDir.absolutePath();

        QDir pluginsDir(projectDir);
        pluginsDir.cd("plugins");

        if (!pluginsDir.exists()) {
            QMessageBox::critical(nullptr, "Error", "Directories do not exist");
            exit(EXIT_FAILURE);
        }

        QStringList pluginsFiles =
         pluginsDir.entryList(QStringList() << pluginExtension, QDir::Files);

        QList<QPointer<QObject>> dependencies;

        foreach (const QString &fileName, pluginsFiles) {
            QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));

            if (!pluginLoader.isLoaded())
                continue;

            QObject *pluginObject = qobject_cast<QObject *>(pluginLoader.instance());

            if (pluginObject) {
                const QMetaObject *metaObject = pluginObject->metaObject();
                int index = metaObject->indexOfClassInfo("Dependencies");

                if (index != -1) {
                    QMetaClassInfo classInfo = metaObject->classInfo(index);
                    QString dependenciesString = classInfo.value();

                    QStringList dependenciesList = dependenciesString.split(";");

                    foreach (QString dependencyName, dependenciesList) {
                        QObject *dependencyObject =
                         QCoreApplication::instance()->findChild<QObject *>(dependencyName);
                        if (dependencyObject) {
                            dependencies.append(QPointer<QObject>(dependencyObject));
                        }
                    }
                }
            }

            BaseInterface *interface = qobject_cast<BaseInterface *>(pluginObject);
            if (interface) {
                interface->initialize(dependencies);
            }
        }
    }
} // namespace Core
