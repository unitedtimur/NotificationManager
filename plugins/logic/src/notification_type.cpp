#include "notification_type.h"

void LogicPlugin::NotificationType::addType(const QString &name)
{
    if (_types.find(name) == _types.end()) {
        ++_nTypes;
        _types[name] = _nTypes;
    }
}

QString LogicPlugin::NotificationType::getType(uint16_t value)
{
    for (auto it = _types.begin(); it != _types.end(); ++it) {
        if (it.value() == value)
            return it.key();
    }
    return "";
}
