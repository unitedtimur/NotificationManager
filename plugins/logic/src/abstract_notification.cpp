#include "abstract_notification.h"

namespace LogicPlugin {
    AbstractNotification::AbstractNotification(const QString &title,
                                               const QString &message,
                                               uint16_t typeID,
                                               const QString &color)
    {
        _title = title;
        _message = message;
        setType(typeID);
        _color = color;
    }

    QString AbstractNotification::title() const
    {
        return _title;
    }

    QString AbstractNotification::message() const
    {
        return _message;
    }

    QString AbstractNotification::type() const
    {
        return TypeManager::stringType(_typeID);
    }

    int32_t AbstractNotification::id() const
    {
        return _id;
    }

    QString AbstractNotification::color() const
    {
        return _color;
    }

    void AbstractNotification::setTitle(const QString &title)
    {
        _title = title;
    }

    void AbstractNotification::setMessage(const QString &message)
    {
        _message = message;
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

    void AbstractNotification::setId(int16_t id)
    {
        _id = id;
    }

    void AbstractNotification::setColor(QString hex)
    {
        _color = hex;
    }
}
