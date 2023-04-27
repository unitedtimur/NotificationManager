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
        return query.exec("CREATE TABLE IF NOT EXISTS notification(Type INT, Title TEXT, "
                          "Description TEXT, Date DATETIME)");
    }

    bool NotificationLogger::insert(QString type, QString tytle, QString descript, QDate date)
    {
        QSqlQuery query(_db);
        query.prepare("INSERT INTO notification(Type, Title, Description, Date) "
                      "VALUES(:type, :tytle, :descript, :date)");
        query.bindValue(":type", QVariant(type));
        query.bindValue(":tytle", QVariant(tytle));
        query.bindValue(":descript", QVariant(descript));
        query.bindValue(":date", QVariant(date));
        return query.exec();
    }
}
