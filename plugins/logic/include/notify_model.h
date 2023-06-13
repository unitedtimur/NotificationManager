#ifndef NOTIFY_MODEL_H
#define NOTIFY_MODEL_H

#include "notification_logger.h"
#include "i_notify_model.h"

#include <QAbstractListModel>
#include <QPointer>
#include <QTimerEvent>

namespace LogicPlugin {
    /*!
     * \brief Класс, который определяет интерфейс, используемый для взаимодействия с компонентами
     * gui
     */
    class NotificationModel final : public QAbstractListModel, public INotifyModel
    {
        Q_OBJECT
    public:
        explicit NotificationModel(QObject *parent = nullptr);

        /*!
         * \brief Смотреть enum Qt::ItemDataRole, User roles
         */
        enum NotificationRoles
        {
            IdRole = Qt::UserRole + 1,
            TitleRole,
            MessageRole,
            TypeRole,
            ColorRole
        };
        Q_ENUM(NotificationRoles)

        /*!
         * \brief Смотреть QAbstractListModel Class
         */
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        QHash<int, QByteArray> roleNames() const override;

        /*!
         * \brief createNotification - метод, вызываемый для создания заранее заготовленых
         * уведомлений
         * \param typeID - id типа уведомления (Default, Warning, etc.)
         */
        void createNotification(uint16_t typeID) override;

        /*!
         * \brief Метод, с помощью которого в модель добавляются данные о новом уведомлении
         */
        void addNotification(QPointer<LogicPlugin::AbstractNotification> notification) override;

        /*!
         * \brief Метод, с помощью которого из модели удаляются данные об уведомлении с определенным
         * индексом
         */
        Q_INVOKABLE void removeNotification(uint16_t id) override;

        void timerEvent(QTimerEvent *event) override;

        /*!
         * \brief Метод, удаляющий информацию о всех уведомлениях в модели
         */
        Q_INVOKABLE void clearNotifications() override;

        /*!
         * \brief Метод, возвращающий количество уведомлений в модели
         */
        int count() const override;

        void reset();

    private:
        /*!
         * \brief logger Ссылка на клаsсс, логирующий в бд
         */
        NotificationLogger &logger = NotificationLogger::instance();
        /*!
         * \brief avalaibleId - метод возвращающий доступный id
         */
        int16_t avalaibleId() const;
        qint32 _timerId;
        /*!
         * \brief Список, в котором хранится информация об всех уведомления в модели
         */
        std::vector<std::unique_ptr<LogicPlugin::AbstractNotification>> _notifications;
    };
}

#endif // NOTIFY_MODEL_H
