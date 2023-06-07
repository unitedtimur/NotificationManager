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
        case ColorRole:
            return notification->color();
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
        roles[ColorRole] = "color";
        return roles;
    }

    void NotificationModel::createNotification(const uint16_t typeID)
    {
        if (LogicPlugin::TypeManager::isTypeExist(typeID)) {
            switch (typeID) {
            case 1: {
                auto notify = new LogicPlugin::AbstractNotification("Обнаружена цель", "some info",
                                                                    typeID, "#E6212131");
                addNotification(notify);
                break;
            }
            case 2: {
                auto warning = new LogicPlugin::AbstractNotification(
                 "Камера не доступна", "some info", typeID, "#E6B04444");
                addNotification(warning);
                break;
            }
            case 3: {
                auto alarm = new LogicPlugin::AbstractNotification(
                 "Высокий уровень шума", "some info", typeID, "#E6B07F00");
                addNotification(alarm);
                break;
            }
            }
        }
    }

    void LogicPlugin::NotificationModel::addNotification(
     QPointer<LogicPlugin::AbstractNotification> notification)
    {
        beginInsertRows(QModelIndex(), _notifications.size(), _notifications.size());
        notification->setId(avalaibleId());
        _notifications.emplace_back(notification);
        logger.insert(notification->type(), notification->title(), notification->description(),
                      QDate::currentDate(), QTime::currentTime().toString("hh:mm:ss"),
                      notification->color());
        endInsertRows();
    }

    void NotificationModel::removeNotification(uint16_t id)
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
        if (_timerId != event->timerId())
            return;
        if (count() > 10)
            return;
        auto warning =
         new LogicPlugin::AbstractNotification("Камера не доступна", "some info", 1, "#B04444");
        addNotification(warning);
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
