#include "abstract_notification.h"


AbstractNotification::AbstractNotification(QString title, QString description, int type)
{
    _title = title;
    _description = description;
    _type = type;
}
