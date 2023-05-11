#include "notification_gui_plugin.h"

#include <QDebug>

namespace GuiPlugin {
    bool NotificationGuiPlugin::initialize(const QList<QPointer<QObject>> &dependencies)
    {
        _core.findPlugins(dependencies, _logicPlugin);
        if (_logicPlugin) {
            qDebug() << Q_FUNC_INFO << "Plugin dependencies found";
            setNotifyModel(_logicPlugin->getNotificationModel());
            setHistoryModel(_logicPlugin->getHistoryModel());
            invoke();
            return true;
        } else {
            qWarning() << Q_FUNC_INFO << "Plugin dependencies not found";
            return false;
        }
    }

    void NotificationGuiPlugin::setNotifyModel(LogicPlugin::NotificationModel *model)
    {
        _notify_model = model;
    }

    void NotificationGuiPlugin::setHistoryModel(LogicPlugin::HistoryModel *model)
    {
        _history_model = model;
    }

    void NotificationGuiPlugin::onRowsInserted(const QModelIndex &parent, int first, int last)
    {
        for (int i = first; i <= last; ++i) {
            QQmlComponent component(&_qmlEngine,
                                    QUrl(QStringLiteral("qrc:/NotificationWindow.qml")));
            QObject *object = component.create();
            if (object) {
                QQuickWindow *window = qobject_cast<QQuickWindow *>(object);
                if (window) {
                    window->setProperty(
                     "title", _notify_model->data(_notify_model->index(i, 0),
                                                  LogicPlugin::NotificationModel::TitleRole));
                    window->setProperty(
                     "message", _notify_model->data(_notify_model->index(i, 0),
                                                    LogicPlugin::NotificationModel::MessageRole));
                    window->setProperty(
                     "type", _notify_model->data(_notify_model->index(i, 0),
                                                 LogicPlugin::NotificationModel::TypeRole));
                    qreal pos = 0;
                    if (_notify_windows_list.count())
                        pos = _notify_windows_list.back()->property("y").toReal();
                    else
                        pos = _screenHeight - 40;
                    pos -= 85;
                    window->setProperty("y", QVariant::fromValue(pos));
                    connectOnVisibleChanged(window);
                    window->show();
                    _notify_windows_list.append(window);
                } else {
                    delete object;
                }
            }
        }
    }

    void NotificationGuiPlugin::invoke()
    {
        _qmlEngine.load(QUrl(QStringLiteral("qrc:/qml/qml/main.qml")));
        _qmlEngine.addImportPath("qrc:/qml");
        calculateLayout();
        setupConnections();
    }

    void NotificationGuiPlugin::calculateLayout()
    {
        QScreen *screen = QGuiApplication::primaryScreen();
        QRect geometry = screen->geometry();
        _screenHeight = screen->size().height() + geometry.y();
    }

    void GuiPlugin::NotificationGuiPlugin::NotificationGuiPlugin::setupConnections()
    {
        QObject::connect(_notify_model, &LogicPlugin::NotificationModel::rowsInserted, this,
                         &NotificationGuiPlugin::onRowsInserted);
    }

    void GuiPlugin::NotificationGuiPlugin::connectOnVisibleChanged(QQuickWindow *window)
    {
        QObject::connect(window, &QQuickWindow::visibleChanged, [&, window]() {
            qreal closedWindowPos = window->property("y").toReal();
            int index = _notify_windows_list.indexOf(window);
            for (auto &w : _notify_windows_list) {
                qreal wPos = w->property("y").toReal();
                if (w != window && wPos < closedWindowPos) {
                    w->setProperty("y", QVariant::fromValue(wPos + 85));
                }
            }
            _notify_model->removeNotification(index);
            _notify_windows_list.removeOne(window);
        });
    }
}
