#include "logic_interface.h"
logic_interface_namespace::LogicInterface::LogicInterface(QObject *parent) : BaseInterface(parent)
{}

bool logic_interface_namespace::LogicInterface::initiliaze(
 const QList<QPointer<QObject> > &dependencies)
{
    return true;
}
