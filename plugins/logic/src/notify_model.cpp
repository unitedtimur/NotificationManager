#include "notify_model.h"
#include "notification_entity.h"

namespace LogicPlugin {
    NotificationModel::NotificationModel(QObject *parent) : QAbstractListModel(parent)
    {
        logger.openDatabase("QSQLITE", "./notify_db.db");
        logger.createTable();
        _timerId = startTimer(1000);
    }

    int NotificationModel::rowCount(const QModelIndex &parent) const
    {
        if (parent.isValid()) {
            return 0;
        }
        return _notifications.count();
    }

    QVariant NotificationModel::data(const QModelIndex &index, int role) const
    {
        if (index.row() > _notifications.size())
            return QVariant();
        const auto notification = _notifications.at(index.row());
        switch (role) {
        case TitleRole:
            return notification->title();
        case MessageRole:
            return notification->description();
        case TypeRole:
            return notification->type();
        default:
            return QVariant();
        }
    }

    QHash<int, QByteArray> NotificationModel::roleNames() const
    {
        QHash<int, QByteArray> roles = QAbstractItemModel::roleNames();
        roles[TitleRole] = "title";
        roles[MessageRole] = "message";
        roles[TypeRole] = "type";
        return roles;
    }

    void NotificationModel::addNotification(AbstractNotification *notification)
    {
        beginInsertRows(QModelIndex(), _notifications.count(), _notifications.count());
        _notifications.push_back(notification);
        logger.insert(notification->type(), notification->title(), notification->description(),
                      QDate::currentDate(), QTime::currentTime().toString("hh:mm:ss"));
        endInsertRows();
    }

    void NotificationModel::removeNotification(int index)
    {
        if (index > _notifications.size())
            return;
        beginRemoveRows(QModelIndex(), index, index);
        _notifications.removeAt(index);
        endRemoveRows();
    }

    void NotificationModel::timerEvent(QTimerEvent *event)
    {
        //    if(_timerId!=event->timerId())
        //        return;
        //    if(count()>10)
        //        return;
        //    auto myImpl = new LogicPlugin::NotificationEntity("test", "Очень важная информация.
        //    Очень важная информация.", 1); addNotification(myImpl);
    }
    void NotificationModel::clearNotifications()
    {
        beginResetModel();
        _notifications.clear();
        endResetModel();
    }

    int NotificationModel::count() const
    {
        return _notifications.count();
    }
}
