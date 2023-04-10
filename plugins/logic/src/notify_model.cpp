#include "notify_model.h"

LogicPlugin::NotificationModel::NotificationModel(QObject *parent) : QAbstractItemModel(parent)
{}
QModelIndex
LogicPlugin::NotificationModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid() || row < 0 || row >= m_notifications.count() || column < 0
        || column >= 3) {
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
    return m_notifications.count();
}

int LogicPlugin::NotificationModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}
QVariant LogicPlugin::NotificationModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= m_notifications.count()
        || index.column() < 0 || index.column() >= 3) {
        return QVariant();
    }
    const Notification &notification = m_notifications.at(index.row());

    switch (role) {
    case Qt::DisplayRole:
        return index.column() == 0 ? notification.title : notification.message;
    case TitleRole:
        return notification.title;
    case MessageRole:
        return notification.message;
    case TypeRole:
        return notification.type;
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

void LogicPlugin::NotificationModel::addNotification(const QString title,
                                                     const QString message,
                                                     const int type)
{
    beginInsertRows(QModelIndex(), m_notifications.count(), m_notifications.count());
    m_notifications.append({ title, message, type });
    endInsertRows();
    emit dataChanged(
     index(m_notifications.count(), 0),
     index(m_notifications.count(), 0)); // Сообщаем QML-интерфейсу, что данные изменились
}

void LogicPlugin::NotificationModel::removeNotification(int index)
{
    if (index >= 0 && index < m_notifications.count()) {
        beginRemoveRows(QModelIndex(), index, index);
        m_notifications.removeAt(index);
        endRemoveRows();
    }
}
void LogicPlugin::NotificationModel::clearNotifications()
{
    beginResetModel();
    m_notifications.clear();
    endResetModel();
}

int LogicPlugin::NotificationModel::count() const
{
    return m_notifications.count();
}
