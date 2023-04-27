#include "abstract_notification.h"

LogicPlugin::AbstractNotification::AbstractNotification(QString title,
                                                        QString description,
                                                        int type)
{
    _title = title;
    _description = description;
    _type = type;
}

const QString LogicPlugin::AbstractNotification::Title()
{
    return _title;
}

const QString LogicPlugin::AbstractNotification::Description()
{
    return _description;
}

const int LogicPlugin::AbstractNotification::Type()
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
