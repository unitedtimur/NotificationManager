#ifndef ABSTRACT_NOTIFICATION_H
#define ABSTRACT_NOTIFICATION_H

#include "logic_plugin_export.h"
#include "notification_type.h"

#include <QString>
#include <QObject>
#include <QDebug>

namespace LogicPlugin {
    /*!
     * \brief Класс, от которого могут наследоваться юзеры библиотеки, чтобы создать новый класс
     * уведомления, если потребуется расширить функционал
     */
    class LOGIC_PLUGIN_EXPORT AbstractNotification: public QObject
    {
    public:
        /*!
         * \brief AbstractNotification конструктор, инициализирующий параметры
         * \param title - строка, в которой храниться название уведомления
         * \param description - строка, в которой храниться более подробное описание уведомления
         * \param type - тип уведомления
         */
        explicit AbstractNotification(QString title, QString description, uint16_t typeID);
        ~AbstractNotification() = default;

        /*!
         * \brief Метод, возвращающий значения переменной _title
         */
        QString title() const;

        /*!
         * \brief Метод, возвращающий значения переменной _description
         */
        QString description() const;

        /*!
         * \brief Метод, возвращающий тип уведомления
         */
        QString type() const;

        /*!
         * \brief Метод, меняющий значение переменной _title
         */
        void setTitle(const QString &title);

        /*!
         * \brief Метод, меняющий значение переменной _description
         */
        void setDescription(const QString &description);

        /*!
         * \brief Метод, меняющий тип уведомления
         */
        void setType(const uint16_t &typeID);

    private:
        /*!
         * \brief приватные поля класса, в них храняться название уведомление, краткое описание и id
         * типа уведомления, к каждому id привязано конкретное название уведомления
         */
        QString _title;
        QString _description;
        uint16_t _typeID;
    };
}

#endif // ABSTRACT_NOTIFICATION_H
