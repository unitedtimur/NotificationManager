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
    return LogicPlugin::TypeManager::stringType(_typeID);
}

void LogicPlugin::AbstractNotification::setTitle(const QString &title)
{
    _title = title;
}

void LogicPlugin::AbstractNotification::setDescription(const QString &description)
{
    _description = description;
}

void LogicPlugin::AbstractNotification::setType(const uint16_t &typeID)
{
    if (LogicPlugin::TypeManager::isTypeExist(typeID)) {
        _typeID = typeID;
    } else {
        qDebug() << Q_FUNC_INFO
                 << " NotificationType structure does not have type with id: " << typeID
                 << "\n NotificationType will be set to default value";
        _typeID = 0;
    }
}
