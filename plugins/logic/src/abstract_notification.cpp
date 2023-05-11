#include "abstract_notification.h"

namespace LogicPlugin {
    AbstractNotification::AbstractNotification(QString title, QString description, uint16_t typeID)
    {
        _title = title;
        _description = description;
        setType(typeID);
    }

    QString AbstractNotification::title() const
    {
        return _title;
    }

    QString AbstractNotification::description() const
    {
        return _description;
    }

    QString AbstractNotification::type() const
    {
        return TypeManager::stringType(_typeID);
    }

    void AbstractNotification::setTitle(const QString &title)
    {
        _title = title;
    }

    void AbstractNotification::setDescription(const QString &description)
    {
        _description = description;
    }

    void AbstractNotification::setType(const uint16_t &typeID)
    {
        if (TypeManager::isTypeExist(typeID)) {
            _typeID = typeID;
        } else {
            qDebug() << Q_FUNC_INFO
                     << " NotificationType structure does not have type with id: " << typeID
                     << "\n NotificationType will be set to default value";
            _typeID = 0;
        }
    }
}
