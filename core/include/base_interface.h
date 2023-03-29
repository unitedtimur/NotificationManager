#ifndef BASE_INTERFACE_H
#define BASE_INTERFACE_H

#include <QObject>

namespace Сore {
    class BaseInterface : public QObject
    {
        Q_OBJECT

    public:
        using QObject::QObject;

        virtual ~BaseInterface() = default;
        virtual bool initialize(const QList<QPointer<QObject>> &dependencies) = 0;
    };
}

Q_DECLARE_INTERFACE(Сore::BaseInterface, "com.сore.BaseInterface")
#endif // BASE_INTERFACE_H
