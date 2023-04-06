#ifndef NOTIFY_MODEL_H
#define NOTIFY_MODEL_H

#include <QAbstractItemModel>
#include "logic_plugin_export.h"

class LOGIC_PLUGIN_EXPORT NotificationModel : public QAbstractItemModel
{
    Q_OBJECT

public:

    explicit NotificationModel(QObject *parent = nullptr);

    enum NotificationTypes
    {
        NOTIFY,
        WARNING,
        ALARM
    };
    enum NotificationRoles
    {
        TitleRole = Qt::UserRole + 1,
        MessageRole,
        TypeRole
    };
    Q_ENUM(NotificationRoles)
    // QAbstractItemModel overrides
    QModelIndex
    index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void addNotification(const QString title, const QString message, const int type);
    void removeNotification(int index);
    void clearNotifications();
    int count() const;

private:
    struct Notification
    {
        QString title;
        QString message;
        int type;
    };

    QList<Notification> m_notifications;
};

#endif // NOTIFY_MODEL_H
