#include "notification_type.h"

std::map<QString, uint16_t> LogicPlugin::NotificationType::_types = {
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
    const auto it = std::find_if(_types.begin(), _types.end(),
                           [&value](const std::pair<QString, uint16_t> &element) {
                                     return element.second == value;
                                 });
    if (it != _types.end()) {
        return it->first;
    } else {
        return "";
    }
}

bool LogicPlugin::NotificationType::isTypeExist(uint16_t value)
{
    const auto it = std::find_if(_types.begin(), _types.end(),
                           [&value](const std::pair<QString, uint16_t> &element) {
                               return element.second == value;
                           });
    if (it != _types.end()) {
        return true;
    } else {
        return false;
    }

}
