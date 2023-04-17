#include "abstract_notification.h"

LogicPlugin::AbstractNotification::AbstractNotification(QString title,
                                                        QString description,
                                                        int type)
{
    _title = title;
    _description = description;
    _type = type;
}

LogicPlugin::AbstractNotification::AbstractNotification(const AbstractNotification &notification)
{
    setTitle(notification._title);
    setDescription(notification._description);
    setType(notification._type);
}

QString LogicPlugin::AbstractNotification::getTitle()
{
    return _title;
}

QString LogicPlugin::AbstractNotification::getDescription()
{
    return _description;
}

int LogicPlugin::AbstractNotification::getType()
{
    return _type;
}

void LogicPlugin::AbstractNotification::setTitle(QString title)
{
    _title = title;
}

void LogicPlugin::AbstractNotification::setDescription(QString description)
{
    _description = description;
}

void LogicPlugin::AbstractNotification::setType(int type)
{
    _type = type;
}
