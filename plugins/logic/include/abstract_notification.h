#ifndef ABSTRACT_NOTIFICATION_H
#define ABSTRACT_NOTIFICATION_H

#include <QString>

class AbstractNotification
{
public:
    AbstractNotification(QString title, QString description, int type);

    QString _title;
    QString _description;
    int _type;
};

#endif // ABSTRACT_NOTIFICATION_H
