#include "abstract_notification.h"

LogicPlugin::AbstractNotification::AbstractNotification(QString title,
                                                        QString description,
                                                        int type)
{
    _title = title;
    _description = description;
    _type = type;
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
