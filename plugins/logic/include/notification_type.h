#ifndef NOTIFICATION_TYPE_H
#define NOTIFICATION_TYPE_H

#include <QString>
#include <QMap>

namespace LogicPlugin {
    class NotificationType
    {
    public:
        //enum Value { NOTIFY, WARNING, ALARM };
        void addType(const QString &name);

        QString getType(uint16_t name);

    private:
        QMap<QString, uint16_t> _types = { { "NOTIFY", 1 }, { "WARNING", 2 }, { "ALARM", 3 } };
//        std::QMap<QString, MyEnum::Value> MyEnum::_types = {
//            {"NOTIFY", MyEnum::NOTIFY},
//            {"WARNING", MyEnum::WARNING},
//            {"ALARM", MyEnum::ALARM}
//        };
        uint16_t _nTypes = 3;
    };
}
#endif // NOTIFICATION_TYPE_H
