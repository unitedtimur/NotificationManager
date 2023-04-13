#pragma once
#include "base_interface.h"
#include <QObject>
#include <iostream>
#include <QString>
#include <QDir>
#include <QMessageBox>
#include <QPluginLoader>
#include <QMetaClassInfo>
#include <QCoreApplication>
#include <QQmlApplicationEngine>
#include <QSettings>


namespace Core {
    /*!
    * \brief Класс, реализующий основной функционал ядра
    */
    class CoreBasis:public QObject
    {
        Q_OBJECT

    public:
        /*!
         * \brief Конструктор класса CoreBasis
         */
        explicit CoreBasis();
        /*!
         * \brief Функция загрузки плагинов
         * Данная функция производит поиск и загрузку плагинов
         */
        void loadPlugins(const QString &path);

        QPointer<QQmlApplicationEngine> qmlEngine() const;
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
}
