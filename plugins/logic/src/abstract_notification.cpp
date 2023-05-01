#include "abstract_notification.h"

LogicPlugin::AbstractNotification::AbstractNotification(QString title,
                                                        QString description,
                                                        uint16_t typeID)
{
    _title = title;
    _description = description;
    setType(typeID);
}

QString LogicPlugin::AbstractNotification::title() const
{
    return _title;
}

QString LogicPlugin::AbstractNotification::description() const
{
    return _description;
}

QString LogicPlugin::AbstractNotification::type() const
{
    return LogicPlugin::NotificationType::stringType(_typeID);
}

void LogicPlugin::AbstractNotification::setTitle(QString title)
{
    _title = title;
}

void LogicPlugin::AbstractNotification::setDescription(QString description)
{
    _description = description;
}

void LogicPlugin::AbstractNotification::setType(uint16_t typeID)
{
    if (LogicPlugin::NotificationType::isTypeExist(typeID))
        _typeID = typeID;
    else {
        qDebug() << Q_FUNC_INFO
                 << " NotificationType structure does not have type with id: " << typeID
                 << "\n NotificationType will be set to default value";
        _typeID = 0;
    }
}
