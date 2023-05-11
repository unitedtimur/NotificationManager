#ifndef TYPE_MANAGER_H
#define TYPE_MANAGER_H

#include <QString>
#include <QMap>
#include <optional>
#include <iostream>
#include <vector>

namespace LogicPlugin {
    /*!
     * \brief Класс, который хранит имеющиеся типы уведомлений, осуществляя функционал
     * добавления новых уведомлений, а также используемый для возвращения названия типа уведомления
     * по его id
     */
    class TypeManager
    {
    public:
        /*!
         * \brief Метод, с помощью которого разработчик может расширить структуру, в которой
         * храняться уведомления и соответсвующие им id
         * \param name - название уведомления, которое требуется добавить
         */
        static std::optional<uint16_t> addType(const QString &name);
        /*!
         * \brief Метод, возвращающий название уведомления с соответсвующим id
         * \param typeID - id уведомления
         */
        const static QString stringType(const uint16_t &typeID);

        /*!
         * \brief Метод, проверяющий существует ли в структуре уведомление с соответсвующим id
         * \param typeID - значение, которое требуется проверить (есть ли это значение в структуре)
         */
        static bool isTypeExist(const uint16_t &typeID);

    private:
        /*!
         * \brief _types - структура, в которой хранятся пары значений (название уведомления и его
         * id)
         */
        static std::map<QString, uint16_t> _types;

    };
}

#endif // TYPE_MANAGER_H
