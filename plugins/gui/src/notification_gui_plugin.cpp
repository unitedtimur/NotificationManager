#include "notification_gui_plugin.h"

#include <QDebug>

namespace GuiPlugin {
    bool NotificationGuiPlugin::initialize(const QList<QPointer<QObject>> &dependencies)
    {
        if (_core.resolve(dependencies, _logicPlugin)) {
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
            QQmlComponent component(
             &_qmlEngine, QUrl(QStringLiteral("qrc:/qml/qml/Notification/NotificationWindow.qml")));

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

                    window->setProperty(
                     "hexcolor", _notify_model->data(_notify_model->index(i, 0),
                                                     LogicPlugin::NotificationModel::ColorRole));

                    int position = Position::TOP_RIGHT;

                    switch (position) {
                    case (Position::BOTTOM_RIGHT):
                        x_start_position = _screenWidth - window->width();
                        y_start_position = _screenHeight;
                        direction_sign = -1;
                        break;
                    case (Position::BOTTOM_LEFT):
                        x_start_position = 0;
                        y_start_position = _screenHeight;
                        direction_sign = -1;
                        break;
                    case (Position::TOP_LEFT):
                        x_start_position = 0;
                        y_start_position = 0;
                        direction_sign = 1;
                        break;
                    case (Position::TOP_RIGHT):
                        x_start_position = _screenWidth - window->width();
                        y_start_position = window->height();
                        direction_sign = 1;
                        break;
                    }

                    x_position = x_start_position;

                    if (_notify_windows_list.count()) {
                        y_position = _notify_windows_list.back()->property("y").toReal();
                        y_position += direction_sign * 5; // интервал между уведомлениями
                    } else
                        y_position = y_start_position; // начальное положение

                    y_position += direction_sign * window->height();

                    window->setProperty("y", QVariant::fromValue(y_position));
                    window->setProperty("x", QVariant::fromValue(x_position));

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
        _qmlEngine.rootContext()->setContextProperty("HistoryModel", _history_model);
        _qmlEngine.load(QUrl(QStringLiteral("qrc:/qml/qml/main.qml")));
        _qmlEngine.addImportPath("qrc:/qml");
        calculateLayout();
        setupConnections();
    }

    void NotificationGuiPlugin::calculateLayout()
    {
        QScreen *screen = QGuiApplication::primaryScreen();
        QSize size = screen->size();
        qDebug() << size.height();
        qDebug() << size.width();

        _screenHeight = size.height();
        _screenWidth = size.width();
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
                    w->setProperty("y",
                                   QVariant::fromValue(wPos + (direction_sign * window->height())));
                }
            }
            _notify_model->removeNotification(index);
            _notify_windows_list.removeOne(window);
        });
    }
}
