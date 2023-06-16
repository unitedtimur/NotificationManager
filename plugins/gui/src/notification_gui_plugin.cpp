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

    void NotificationGuiPlugin::setDisplayCorner(int32_t position)
    {
        _notify_windows_list.clear();

        switch (position) {
        case (Position::BOTTOM_RIGHT):
            _x_start_position = _screenWidth - _windowWidth;
            _y_start_position = _screenHeight;
            direction_sign = -1;
            break;
        case (Position::BOTTOM_LEFT):
            _x_start_position = 0;
            _y_start_position = _screenHeight;
            direction_sign = -1;
            break;
        case (Position::TOP_LEFT):
            _x_start_position = 0;
            _y_start_position = 0;
            direction_sign = 1;
            break;
        case (Position::TOP_RIGHT):
            _x_start_position = _screenWidth - _windowWidth;
            _y_start_position = 0;
            direction_sign = 1;
            break;
        }
    }

    QQuickWindow *NotificationGuiPlugin::createWindow(const QString &path, qint32 ix)
    {
        if (!_qmlEngine) {
            qWarning() << "Failed to create" << path.toUtf8().data()
                       << "- engine was already destroyed";
            return nullptr;
        }
        QQmlComponent component(_qmlEngine, QUrl(path));
        auto item = createWindow(component, ix);
        if (!item)
            qWarning() << "Failed to create window";
        return item;
    }

    QQuickWindow *NotificationGuiPlugin::createWindow(QQmlComponent &component, qint32 ix)
    {
        auto object = createObject(component, nullptr, ix);
        if (!object)
            return nullptr;
        auto window = qobject_cast<QQuickWindow *>(object);
        if (!window) {
            auto file = component.url().toLocalFile();
            auto errorMessage = QString("Filed to create %1: %2 is not a QQuickWIndow")
                                 .arg(file, object->metaObject()->className());
            qWarning() << errorMessage.toUtf8().data();
            delete object;
            return nullptr;
        }
        return window;
    }

    QObject *
    NotificationGuiPlugin::createObject(QQmlComponent &component, QObject *parent, qint32 ix)
    {
        auto object = component.beginCreate(context(parent));

        if (!object)
            return nullptr;

        object->setProperty("title",
                            _notify_model->data(_notify_model->index(ix, 0),
                                                LogicPlugin::NotificationModel::TitleRole));

        object->setProperty("message",
                            _notify_model->data(_notify_model->index(ix, 0),
                                                LogicPlugin::NotificationModel::MessageRole));

        object->setProperty("type", _notify_model->data(_notify_model->index(ix, 0),
                                                        LogicPlugin::NotificationModel::TypeRole));

        object->setProperty("hexcolor",
                            _notify_model->data(_notify_model->index(ix, 0),
                                                LogicPlugin::NotificationModel::ColorRole));

        component.completeCreate();

        object->setParent(parent);
        return object;
    }

    QQmlContext *NotificationGuiPlugin::context(QObject *object) const
    {
        if (!_qmlEngine)
            return nullptr;
        return object ? _qmlEngine->contextForObject(object) : _qmlEngine->rootContext();
    }

    void NotificationGuiPlugin::onRowsInserted(const QModelIndex &parent, int ix)
    {
        qDebug() << "ix " << ix;

        QQuickWindow *window = createWindow("qrc:/qml/qml/Notification/NotificationWindow.qml", ix);

        x_position = _x_start_position;
        if (_notify_windows_list.count()) {
            y_position = _notify_windows_list.back()->property("y").toReal();
            y_position += direction_sign * margin; // интервал между уведомлениями
            //                        qDebug() << "RUNTIME " << y_position;

        } else {
            y_position = _y_start_position; // начальное положение
            //                        qDebug() << "RESET " << y_position;
        }

        y_position += direction_sign * window->height();
        window->setProperty("y", QVariant::fromValue(y_position));
        window->setProperty("x", QVariant::fromValue(x_position));
        // _qmlEngine.rootContext()->setProperty("notificationWindow",
        // QVariant::fromValue(*window));
        connectOnVisibleChanged(window);
        window->show();
        _notify_windows_list.append(window);
    }

    void NotificationGuiPlugin::invoke()
    {
        _qmlEngine->rootContext()->setContextProperty("HistoryModel", _history_model);
        _qmlEngine->rootContext()->setContextProperty("GUI", this);

        _qmlEngine->load(QUrl(QStringLiteral("qrc:/qml/qml/main.qml")));
        _qmlEngine->addImportPath("qrc:/qml");
        calculateLayout();
        setupConnections();
        setDisplayCorner(Position::BOTTOM_RIGHT);
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
        // qDebug() << "Entered";
        QObject::connect(window, &QQuickWindow::visibleChanged, [&, window]() {
            // qDebug() << "Entered in";
            qreal closedWindowPos = window->property("y").toReal();
            if (direction_sign == 1) {
                for (int i = _notify_windows_list.size() - 1; i >= 0; --i) {
                    qreal windowPos = _notify_windows_list[i]->property("y").toReal();
                    if (_notify_windows_list[i] != window && windowPos > closedWindowPos)
                        _notify_windows_list[i]->setProperty(
                         "y", QVariant::fromValue(windowPos - window->height() - margin));
                }
            } else {
                for (int i = 0; i < _notify_windows_list.size(); ++i) {
                    qreal windowPos = _notify_windows_list[i]->property("y").toReal();
                    if (_notify_windows_list[i] != window && windowPos < closedWindowPos)
                        _notify_windows_list[i]->setProperty(
                         "y", QVariant::fromValue(windowPos + window->height() + margin));
                }
            }
            uint16_t index = _notify_windows_list.indexOf(window);
            _notify_model->removeNotification(index);
            _notify_windows_list.removeOne(window);
        });
    }
}
