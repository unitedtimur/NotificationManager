#include "notification_info.h"

Common::NotificationInfo::NotificationInfo(QString summary,
                                           QString body,
                                           NotifyCategory category,
                                           int expire_timeout) :
    _summary(summary),
    _body(body), _category(category), _expire_timeout(expire_timeout)
{}
