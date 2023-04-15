#ifndef CONNECT_INTERFACE_H
#define CONNECT_INTERFACE_H

#include <QObject>

class ConnectInterface : public QObject
{
    Q_OBJECT
public:
    using QObject::QObject;
    virtual ~ConnectInterface() = default;
    virtual bool printName() = 0;
};

// говорим компилятору сгенерировать метаинформацию для строки-идентификатор
#define ConnectInterface_iid "com.mysoft.ConnectInterface"
Q_DECLARE_INTERFACE(ConnectInterface, ConnectInterface_iid)

#endif // CONNECT_INTERFACE_H
