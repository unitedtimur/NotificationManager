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
    class AbstractNotification : public QObject
    {
    public:
        Q_PROPERTY(QString title MEMBER _title READ title WRITE setTitle);
        Q_PROPERTY(QString description MEMBER _description READ description WRITE setDescription);
        Q_PROPERTY(uint16_t type MEMBER _typeID READ type WRITE setType);
        Q_PROPERTY(uint16_t id MEMBER _id READ id WRITE setId);
        Q_PROPERTY(QString color MEMBER _color READ color WRITE setColor);
        /*!
         * \brief AbstractNotification конструктор, инициализирующий параметры
         * \param title - строка, в которой храниться название уведомления
         * \param description - строка, в которой храниться более подробное описание уведомления
         * \param type - тип уведомления
         */
        explicit AbstractNotification(const QString &title,
                                      const QString &description,
                                      uint16_t typeID,
                                      const QString &color);
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
         * \brief Метод, возвращающий номер уведомления в очереди уведомлений
         */
        int32_t id() const;

        /*!
         * \brief Метод, возвращающий цвеь уведомления
         */
        QString color() const;

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

        /*!
         * \brief Метод, меняющий номер уведомления в очереди уведомлений
         */
        void setId(int16_t id);

        /*!
         * \brief Метод, меняющий цвет уведомления
         * \param hex - hex color code
         */
        void setColor(QString hex);

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

        /*!
         * \brief Приватное поле класса, хранящее номер уведомления в очереди уведомлений
         */
        int16_t _id { -1 };

        /*!
         * \brief Приватное поле класса, хранящее цвеь уведомления в виде хексового кода
         */
        QString _color;
    };
}

#endif // ABSTRACT_NOTIFICATION_H
