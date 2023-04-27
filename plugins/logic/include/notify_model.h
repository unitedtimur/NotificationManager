#ifndef NOTIFY_MODEL_H
#define NOTIFY_MODEL_H

#include "logic_plugin_export.h"
#include "abstract_notification.h"
#include "notification_logger.h"
#include <QAbstractItemModel>
#include <QPointer>
namespace LogicPlugin {
    /*!
     * \brief Класс, который определяет интерфейс, используемый для взаимодействия с компонентами
     * gui
     */
    class LOGIC_PLUGIN_EXPORT NotificationModel : public QAbstractItemModel
    {
        Q_OBJECT

    public:
        explicit NotificationModel(QObject *parent = nullptr);
        /*!
         * \brief Смотреть enum Qt::ItemDataRole, User roles
         */
        enum NotificationRoles
        {
            TitleRole = Qt::UserRole + 1,
            MessageRole,
            TypeRole
        };
        Q_ENUM(NotificationRoles)
        QModelIndex
        /*!
         * \brief QAbstractItemModel Class
         */
        index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
        QModelIndex parent(const QModelIndex &child) const override;
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        int columnCount(const QModelIndex &parent = QModelIndex()) const override;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        QHash<int, QByteArray> roleNames() const override;

        /*!
         * \brief Метод, с помощью которого в модель добавляются данные о новом уведомлении
         */
        void addNotification(QPointer<LogicPlugin::AbstractNotification> notification);

        /*!
         * \brief Метод, с помощью которого из модели удаляются данные об уведомлении с определенным
         * индексом
         */
        void removeNotification(int index);

        /*!
         * \brief Метод, удаляющий информацию о всех уведомлениях в модели
         */
        void clearNotifications();

        /*!
         * \brief Метод, возвращающий количество уведомлений в модели
         */
        int count() const;

    private:
        NotificationLogger &logger = NotificationLogger::instance();
        /*!
         * \brief Список, в котором хранится информация об всех уведомления в модели
         */
        QList<QPointer<LogicPlugin::AbstractNotification>> _notifications;
    };
}

#endif // NOTIFY_MODEL_H
