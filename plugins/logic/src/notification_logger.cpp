#include "notification_logger.h"

namespace LogicPlugin {
    QSqlDatabase NotificationLogger::_db;

    NotificationLogger &NotificationLogger::instance()
    {
        static NotificationLogger db;
        return db;
    }

    bool NotificationLogger::openDatabase(QString type, QString name)
    {
        _db = QSqlDatabase::addDatabase(type);
        _db.setDatabaseName(name);
        return _db.isValid() && _db.open();
    }

    void NotificationLogger::close()
    {
        _db.close();
    }

    bool NotificationLogger::createTable()
    {
        QSqlQuery query(_db);
        query.prepare("CREATE TABLE IF NOT EXISTS notification(Type TEXT, Title TEXT, "
                      "Description TEXT, Date DATE, Time TIME)");
        return query.exec();
    }

    bool NotificationLogger::insert(
     QString type, QString title, QString descript, QDate date, QString time)
    {
        QSqlQuery query(_db);
        query.prepare("INSERT INTO notification(Type, Title, Description, Date, Time) "
                      "VALUES(:type, :title, :descript, :date, :time)");
        query.bindValue(":type", QVariant::fromValue(type));
        query.bindValue(":title", QVariant::fromValue(title));
        query.bindValue(":descript", QVariant::fromValue(descript));
        query.bindValue(":date", QVariant::fromValue(date));
        query.bindValue(":time", QVariant::fromValue(time));
        return query.exec();
    }
}
