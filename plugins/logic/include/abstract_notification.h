#ifndef ABSTRACT_NOTIFICATION_H
#define ABSTRACT_NOTIFICATION_H

#include "type_manager.h"

#include <QString>
#include <QObject>
#include <QDebug>

namespace LogicPlugin {
    /*!
     * \brief Класс, от которого могут наследоваться юзеры библиотеки, чтобы создать новый класс
     * уведомления, если потребуется расширить функционал
     */
    class  AbstractNotification: public QObject
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
       Q_INVOKABLE QString title() const;

        /*!
         * \brief Метод, возвращающий значения переменной _description
         */
       Q_INVOKABLE QString description() const;

        /*!
         * \brief Метод, возвращающий тип уведомления
         */
       Q_INVOKABLE QString type() const;

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
         * \brief Приватное поле класса, хранящее название переменной уведомления
         */
        QString _title;

        /*!
         * \brief Приватное поле класса, хранящее краткое описание уведомления
         */
        QString _description;

        /*!
         * \brief Приватное поле класса, хранящее id типа уведомления, к каждому id привязано
         * конкретное название уведомления
         */
        uint16_t _typeID;
    };
}

#endif // ABSTRACT_NOTIFICATION_H
