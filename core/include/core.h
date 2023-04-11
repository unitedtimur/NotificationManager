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
        void loadPlugins();
};
}
