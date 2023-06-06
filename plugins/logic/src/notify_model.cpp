#include "notify_model.h"

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
        return _notifications.size();
    }

    QVariant NotificationModel::data(const QModelIndex &index, int role) const
    {
        if (index.row() > _notifications.size())
            return QVariant();
        const auto notification = _notifications.at(index.row()).get();
        switch (role) {
        case IdRole:
            return notification->id();
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
        roles[IdRole] = "id";
        roles[TitleRole] = "title";
        roles[MessageRole] = "message";
        roles[TypeRole] = "type";
        return roles;
    }

    void LogicPlugin::NotificationModel::addNotification(
     QPointer<LogicPlugin::AbstractNotification> notification)
    {
        beginInsertRows(QModelIndex(), _notifications.size(), _notifications.size());
        notification->setId(avalaibleId());
        _notifications.emplace_back(notification);
        logger.insert(notification->type(), notification->title(), notification->description(),
                      QDate::currentDate(), QTime::currentTime().toString("hh:mm:ss"));
        endInsertRows();
    }

    void NotificationModel::removeNotification(int id)
    {
        const auto it = std::lower_bound(_notifications.begin(), _notifications.end(), id,
                                         [](const auto &notification, auto id) {
                                             return notification->id() < id;
                                         });

        if (it == _notifications.end())
            return;

        const auto index = std::distance(_notifications.begin(), it);
        beginRemoveRows(QModelIndex(), index, index);
        _notifications.erase(it);
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
        return _notifications.size();
    }

    int16_t LogicPlugin::NotificationModel::avalaibleId() const
    {
        return _notifications.empty() ? 0 : _notifications.back()->id() + 1;
    }
}
