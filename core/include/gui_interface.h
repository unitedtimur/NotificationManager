#ifndef GUI_INTERFACE_H
#define GUI_INTERFACE_H

#include "base_interface.h"

namespace Core {
    /*!
     * \brief Класс, реализующий плагин интерфейса(то есть в дальнейшем здесь будут описаны все
     * методы, классы, которые понадобяться для реализации задачи отображения графических элементов, а сам GuiInterface будет собран в библиотеку)
     */
    class GuiInterface : public BaseInterface
    {
        Q_OBJECT
        Q_INTERFACES(Core::BaseInterface)
    };
}

Q_DECLARE_INTERFACE(Core::GuiInterface, "com.Core.GuiInterface")

#endif // GUI_INTERFACE_H
