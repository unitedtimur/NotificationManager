#include "notification_type.h"

std::map<QString, uint16_t> LogicPlugin::NotificationType::_types = {
    { "DEFAULT", 0 }, { "NOTIFY", 1 }, { "WARNING", 2 }, { "ALARM", 3 }
};

std::optional<uint16_t> LogicPlugin::NotificationType::addType(const QString &name)
{
    if (name.isEmpty())
        return std::nullopt;
    const auto it = std::find_if(_types.begin(), _types.end(),
                                 [&name](const std::pair<QString, uint16_t> &element) {
                                     return element.first == name;
                                 });
    if (it != _types.end()) { // если тип уедомления с названием name уже существует, то мы ничего
                              // не добавляем в структуру
        return std::nullopt;
    } else {
        ++_nTypes;
        _types[name] = _nTypes;
        return { it->second };
    }
}

const QString LogicPlugin::NotificationType::stringType(const uint16_t &value)
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

bool LogicPlugin::NotificationType::isTypeExist(const uint16_t &value)
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
