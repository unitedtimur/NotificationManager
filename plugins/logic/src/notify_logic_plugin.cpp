#include "notify_logic_plugin.h"

LogicPlugin::NotificationLogicPlugin::NotificationLogicPlugin(QObject *parent) : QObject(parent)
{}

bool LogicPlugin::NotificationLogicPlugin::hasNotifications()
{
    return !_notify_list.isEmpty();
}

void LogicPlugin::NotificationLogicPlugin::addNotification(NotificationInfo notify)
{
    _notify_list.append(notify);
}

void LogicPlugin::NotificationLogicPlugin::clearList()
{
    _notify_list.clear();
}

bool LogicPlugin::NotificationLogicPlugin::initialize(const QList<QPointer<QObject> > &dependencies)
{
    return true;
}

void LogicPlugin::NotificationLogicPlugin::setEnabled(bool value)
{
    if (_enabled != value) {
        _enabled = value;
        emit enabledChangedNotifications(value);
    }
}

void LogicPlugin::NotificationLogicPlugin::showNextNotification()
{
    if (hasNotifications()) {
        _notify_list.first()._timer = new QTimer(this);
        connect(_notify_list.first()._timer, &QTimer::timeout, this,
                &LogicPlugin::NotificationLogicPlugin::removeNotification);
        emit showNotificationSignal(_notify_list.first());
        _countOfNotifications++;
    }
}

void LogicPlugin::NotificationLogicPlugin::removeNotification()
{
    _notify_list.pop_front();
    emit removeNotificationSignal();
    _countOfNotifications--;
}
