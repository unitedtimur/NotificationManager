#ifndef NOTIFICATIONINFO_H
#define NOTIFICATIONINFO_H
#include <QString>
#include <QTimer>
namespace Common {
    /*
         Перечисление типов уведомлений
    */
    enum class NotifyCategory
    {
        WARNING,
        ALARM,
        NOTIFY
    };
    /*
       информацию об уведомлении
    */
    class NotificationInfo
    {
    public:
        NotificationInfo(QString summary,
                         QString body,
                         NotifyCategory category,
                         int expire_timeout);
        QString _summary;
        QString _body;
        NotifyCategory _category;
        int _expire_timeout;
        QTimer *_timer = 0;
    };
}
#endif // NOTIFICATIONINFO_H
