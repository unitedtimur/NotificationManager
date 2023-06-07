#ifndef NOTIFICATION_LOGGER_H
#define NOTIFICATION_LOGGER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSql>
#include <QFile>
#include <QDate>
#include <QVariant>

namespace LogicPlugin {
    /*!
     *\brief
     *Класс синглтон, реализующий базу данных для логирования уведомлений
     */
    class NotificationLogger : public QObject
    {
    public:
        /*!
         * \brief instance Метод, который создает единственный статический экземпляр класса
         * \return Возвращает на него ссылку
         */
        static NotificationLogger &instance();

        /*!
         * \brief openDatabase Метод открывает соединение с базой данных
         * \param type Тип базы данных ("QSQLITE")
         * \param name Имя базы данных
         * \return Возвращает true, если соединение установлено успешно, иначе false
         */
        bool openDatabase(QString type, QString name);

        /*!
         * \brief createTable Создает таблицу в базе данных
         * \return Возвращает true, если запрос успешно выполнен, иначе false
         */
        bool createTable();

        /*!
         * \brief insert Метод для добавления строки в базу данных, используя подговленный запрос
         * \param type - Тип уведомления
         * \param tytle - Заголовок уведомления
         * \param descript - Описание
         * \param date - Дата
         * \param color - цвет уведомления
         * \return Возвращает true, если запрос успешно выполнен, иначе false
         */
        bool insert(
         QString type, QString tytle, QString descript, QDate date, QString time, QString color);

        /*!
         * \brief close Метод закрывает соединение с базой данных
         */
        void close();

    private:
        /*!
         * \brief Синглтон, приватные удаленные конструктор по умолчанию,
         * конструктор копирования, оператор =, гарантирующие создание только одного экземпляра
         * класса
         */
        explicit NotificationLogger() = default;
        ~NotificationLogger() = default;
        NotificationLogger(const NotificationLogger &) = delete;
        NotificationLogger &operator=(NotificationLogger) = delete;

        /*!
         * \brief _db - Статический обьект для установки соединения с базой данных
         */

        static QSqlDatabase _db;
    };
}

#endif // NOTIFICATION_LOGGER_H
