#include "notification_type.h"

QMap<QString, uint16_t> LogicPlugin::NotificationType::_types = {
    { "DEFAULT", 0 }, { "NOTIFY", 1 }, { "WARNING", 2 }, { "ALARM", 3 }
};

void LogicPlugin::NotificationType::addType(const QString &name)
{
    if (name != "") {
        if (_types.find(name) == _types.end()) {
            ++_nTypes;
            _types[name] = _nTypes;
        }
    }
}

const QString LogicPlugin::NotificationType::stringType(uint16_t value)
{
    for (auto it = _types.begin(); it != _types.end(); ++it) {
        if (it.value() == value)
            return it.key();
    }
    return "";
}

bool LogicPlugin::NotificationType::isTypeExist(uint16_t value)
{
    for (auto it = _types.begin(); it != _types.end(); ++it) {
        if (it.value() == value)
            return true;
    }
    return false;
}
