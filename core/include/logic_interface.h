#ifndef LOGIC_INTERFACE_H
#define LOGIC_INTERFACE_H

#include "base_interface.h"

namespace NMCore {
    /*!
     * \brief Класс, реализующий плагин бизнес-логики(то есть в дальнейшем здесь будут описаны все
     * методы, классы, которые понадобяться для реализации логики отображения уведомлений,
     * а сам LogicInterface будет собран в библиотеку)
     */
    class LogicInterface : public BaseInterface
    {
        Q_OBJECT
        Q_INTERFACES(NMCore::BaseInterface)
    public:
    };
}

Q_DECLARE_INTERFACE(NMCore::LogicInterface, "com.NM.Core.LogicInterface")

#endif // LOGIC_INTERFACE_H
