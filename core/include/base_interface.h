#ifndef BASE_INTERFACE_H
#define BASE_INTERFACE_H

#include <QObject>
#include <QList>
#include <QPointer>
/*!
 * \brief Класс, являющийся базовым интерфейсом, от него будут
 * наследоваться плагины логики и gui
 */
class BaseInterface : public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief Для класса BaseInterface используется базовый
     * конструктор QObject
     */
    using QObject::QObject;
    /*!
     * \brief Виртуальный деструктор с определением в хедере
     */
    virtual ~BaseInterface() = default;
    /*!
     * \brief Виртуальный метод, который реализует инициализацию плагинов
     * логики и gui, исходя из зависимостей библиотек друг от друга
     */
    virtual bool initialize() = 0;
};

Q_DECLARE_INTERFACE(BaseInterface, "com.core.BaseInterface")
#endif // BASE_INTERFACE_H
