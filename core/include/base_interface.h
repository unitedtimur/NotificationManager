#ifndef BASE_INTERFACE_H
#define BASE_INTERFACE_H
#pragma once

#include <QObject>
#include <QList>
#include <QPointer>

namespace base_interface_namespace {

    class BaseInterface : public QObject
    {
        Q_OBJECT

    public:
        using QObject::QObject;
        virtual ~BaseInterface() = default;
        virtual bool initialize(const QList<QPointer<QObject>> &dependencies) = 0;
    };
}
Q_DECLARE_INTERFACE(base_interface_namespace::BaseInterface, "com.сore.BaseInterface")

#endif // BASE_INTERFACE_H
