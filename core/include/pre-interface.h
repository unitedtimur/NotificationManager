#ifndef PREINTERFACE_H
#define PREINTERFACE_H

#include "connect_interface.h"

class PreInterface : public ConnectInterface
{
    Q_OBJECT
    Q_INTERFACES(ConnectInterface)
public:
    //    virtual ~PreInterface() = default;
};

Q_DECLARE_INTERFACE(PreInterface, "com.core.PreInterface")

#endif // PREINTERFACE_H
