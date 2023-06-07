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
                      "Description TEXT, Date DATE, Time TIME, Color TEXT)");
        return query.exec();
    }

    bool NotificationLogger::insert(
     QString type, QString title, QString descript, QDate date, QString time, QString color)
    {
        QSqlQuery query(_db);
        query.prepare("INSERT INTO notification(Type, Title, Description, Date, Time, Color) "
                      "VALUES(:type, :title, :descript, :date, :time, :color)");
        query.bindValue(":type", QVariant::fromValue(type));
        query.bindValue(":title", QVariant::fromValue(title));
        query.bindValue(":descript", QVariant::fromValue(descript));
        query.bindValue(":date", QVariant::fromValue(date));
        query.bindValue(":time", QVariant::fromValue(time));
        query.bindValue(":color", QVariant::fromValue(color));
        return query.exec();
    }
}
