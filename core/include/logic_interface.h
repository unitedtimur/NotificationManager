#ifndef LOGIC_INTERFACE_H
#define LOGIC_INTERFACE_H
#include "base_interface.h"
namespace logic_interface_namespace {
    class LogicInterface : public BaseInterface
    {
        Q_OBJECT
        Q_INTERFACES(BaseInterface)
    public:
        explicit LogicInterface(QObject *parent = nullptr);
        virtual bool initiliaze(const QList<QPointer<QObject>> &dependencies);
    };
}
Q_DECLARE_INTERFACE(logic_interface_namespace::LogicInterface, "com.сore.LogicInterface")
#endif // LOGIC_INTERFACE_H
