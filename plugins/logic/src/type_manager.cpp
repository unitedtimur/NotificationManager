#include "type_manager.h"

std::map<QString, uint16_t> LogicPlugin::TypeManager::_types = {
    { "DEFAULT", 0 }, { "NOTIFY", 1 }, { "WARNING", 2 }, { "ALARM", 3 }
};

std::optional<uint16_t> LogicPlugin::TypeManager::addType(const QString &name)
{
    if (name.isEmpty())
        return std::nullopt;
    const auto it = std::find_if(_types.begin(), _types.end(),
                                 [&name](const auto &element) {
                                     return element.first == name;
                                 });
    if (it != _types.end()) // если тип уедомления с названием name уже существует, то мы ничего
                            // не добавляем в структуру
        return std::nullopt;
    _types[name] = _types.size() + 1;
    return { it->second };
}

const QString LogicPlugin::TypeManager::stringType(const uint16_t &value)
{
    const auto it = std::find_if(_types.begin(), _types.end(),
                                 [&value](const auto &element) {
                                     return element.second == value;
                                 });
    if (it != _types.end())
        return it->first;
    return "";
}

bool LogicPlugin::TypeManager::isTypeExist(const uint16_t &value)
{
    const auto it = std::find_if(_types.begin(), _types.end(),
                                 [&value](const auto &element) {
                                     return element.second == value;
                                 });
    if (it != _types.end())
        return true;
    return false;
}
