#include "notification_logger.h"
namespace LogicPlugin {
    QSqlDatabase NotificationLogger::_db;

    NotificationLogger &NotificationLogger::instance()
    {
        static NotificationLogger db;
        return db;
    }
    bool NotificationLogger::createDatabase(QString db_type, QString db_name)
    {
        _db = QSqlDatabase::addDatabase(db_type);
        _db.setDatabaseName(db_name);
        return _db.isValid() && _db.open();
    }
    bool NotificationLogger::createTable()
    {
        QSqlQuery query;
        return query.exec(
         "CREATE TABLE notification(Type INT, Title TEXT, Description TEXT, Date DATETIME)");
    }
    bool NotificationLogger::insert(int type, QString tytle, QString descript, QDate date)
    {
        QSqlQuery query;
        query.prepare("INSERT INTO notification(Type, Title, Description, Date) "
                      "VALUES(:type, :tytle, :descript, :date)");
        query.bindValue(":type", QVariant(type));
        query.bindValue(":tytle", QVariant(tytle));
        query.bindValue(":descript", QVariant(descript));
        query.bindValue(":date", QVariant(date));
        return query.exec();
    }
}
