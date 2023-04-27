#ifndef NOTIFICATIONLOGGER_H
#define NOTIFICATIONLOGGER_H

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
         * \brief instance метод, который создает единственный статический экземпляр класса
         * \return возвращает на него ссылку
         */
        static NotificationLogger &instance();
        /*!
         * \brief openDatabase метод открывает соединение с базой данных, используя заданный  .
         * \param type тип базы данных ("QSQLITE")
         * \param name имя базы данных
         * \return возвращает true, если соединение установлено успешно, иначе false
         */
        bool openDatabase(QString type, QString name);
        /*!
         * \brief createTable создает таблицу в базе данных
         * \return возвращает true, если запрос успешно выполнен, иначе false
         */
        bool createTable();
        /*!
         * \brief insert метод для добавления строки в базу данных, используя подговленный запрос
         * \param type - тип уведомления
         * \param tytle - заголовок уведомления
         * \param descript - описание
         * \param date - дата
         * \return возвращает true, если запрос успешно выполнен, иначе false
         */
        bool insert(QString type, QString tytle, QString descript, QDate date);
        /*!
         * \brief close метод закрывает соединение с базой данных
         */
        void close();

    private:
        /*!
         * \brief синглтон Майерса, приватные удаленные конструктор по умолчанию,
         * конструктор копирования, оператор =, гарантирующие создание только одного экземпляра
         * класса
         */
        explicit NotificationLogger() = default;
        ~NotificationLogger() = default;
        NotificationLogger(const NotificationLogger &) = delete;
        NotificationLogger &operator=(NotificationLogger) = delete;
        static QSqlDatabase _db;
    };
}

#endif // NOTIFICATIONLOGGER_H
