#include "notify_model.h"

LogicPlugin::NotificationModel::NotificationModel(QObject *parent) : QAbstractItemModel(parent)
{}
QModelIndex
LogicPlugin::NotificationModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid() || row < 0 || row >= _notifications.count() || column < 0 || column >= 3) {
        return QModelIndex();
    }
    return createIndex(row, column);
}

QModelIndex LogicPlugin::NotificationModel::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);
    return QModelIndex();
}

int LogicPlugin::NotificationModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    return _notifications.count();
}

int LogicPlugin::NotificationModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}
QVariant LogicPlugin::NotificationModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= _notifications.count()
        || index.column() < 0 || index.column() >= 3) {
        return QVariant();
    }
    AbstractNotification notification(_notifications.at(index.row()));

    switch (role) {
    case Qt::DisplayRole:
        return index.column() == 0 ? notification.getTitle() : notification.getDescription();
    case TitleRole:
        return notification.getTitle();
    case MessageRole:
        return notification.getDescription();
    case TypeRole:
        return notification.getType();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> LogicPlugin::NotificationModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractItemModel::roleNames();
    roles[TitleRole] = "title";
    roles[MessageRole] = "message";
    roles[TypeRole] = "type";
    return roles;
}

void LogicPlugin::NotificationModel::addNotification(
 QPointer<LogicPlugin::AbstractNotification> notification)
{
    beginInsertRows(QModelIndex(), _notifications.count(), _notifications.count());
    _notifications.push_back(*notification);
    endInsertRows();
    emit dataChanged(
     index(_notifications.count(), 0),
     index(_notifications.count(), 0)); // Сообщаем QML-интерфейсу, что данные изменились
}

void LogicPlugin::NotificationModel::removeNotification(int index)
{
    if (index >= 0 && index < _notifications.count()) {
        beginRemoveRows(QModelIndex(), index, index);
        _notifications.removeAt(index);
        endRemoveRows();
    }
}
void LogicPlugin::NotificationModel::clearNotifications()
{
    beginResetModel();
    _notifications.clear();
    endResetModel();
}

int LogicPlugin::NotificationModel::count() const
{
    return _notifications.count();
}
