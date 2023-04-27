#ifndef NOTIFICATIONLOGGER_H
#define NOTIFICATIONLOGGER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSql>
#include <QFile>
#include <QDate>
#include <QVariant>

namespace LogicPlugin {
    class NotificationLogger : public QObject
    {
    public:
        static NotificationLogger &instance();
        bool openDatabase(QString type, QString name);
        bool createTable();
        bool insert(QString type, QString tytle, QString descript, QDate date);
        void close();

    private:
        explicit NotificationLogger() = default;
        ~NotificationLogger() = default;
        NotificationLogger(const NotificationLogger &) = delete;
        NotificationLogger &operator=(NotificationLogger) = delete;
        static QSqlDatabase _db;
    };
}

#endif // NOTIFICATIONLOGGER_H
