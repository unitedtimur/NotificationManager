#include "notify_model.h"

NotificationModel::NotificationModel(QObject *parent) : QAbstractItemModel(parent)
{}
QModelIndex NotificationModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid() || row < 0 || row >= m_notifications.count() || column < 0
        || column >= 3) {
        return QModelIndex();
    }

    return createIndex(row, column);
}

QModelIndex NotificationModel::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);
    return QModelIndex();
}

int NotificationModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }

    return m_notifications.count();
}

int NotificationModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}
QVariant NotificationModel::data(const QModelIndex &index, int role) const
{
   // qDebug() << "data role:" << role << "row:" << index.row() << "col:" << index.column();

    if (!index.isValid() || index.row() < 0 || index.row() >= m_notifications.count()
        || index.column() < 0 || index.column() >= 3) {
        return QVariant();
    }
    const Notification &notification = m_notifications.at(index.row());

    switch (role) {
    case Qt::DisplayRole:
        return index.column() == 0 ? notification.title : notification.message;
    case TitleRole:
        return notification.title; // QVariant::fromValue?
    case MessageRole:
        return notification.message;
    case TypeRole:
        return notification.type;
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
   // qDebug() << roles[TitleRole] << roles[MessageRole];
    return roles;
}

void NotificationModel::addNotification(const QString title, const QString message, const int type)
{
    beginInsertRows(QModelIndex(), m_notifications.count(), m_notifications.count());
    m_notifications.append({ title, message, type });
    endInsertRows();
    emit dataChanged(
        index(m_notifications.count(), 0),
        index(m_notifications.count(), 0)); // Сообщаем QML-интерфейсу, что данные изменились
}

void NotificationModel::removeNotification(int index)
{
    if (index >= 0 && index < m_notifications.count()) {
        beginRemoveRows(QModelIndex(), index, index);
        m_notifications.removeAt(index);
        endRemoveRows();
    }
}
void NotificationModel::clearNotifications()
{
    beginResetModel();
    m_notifications.clear();
    endResetModel();
}

int NotificationModel::count() const
{
    return m_notifications.count();
}
