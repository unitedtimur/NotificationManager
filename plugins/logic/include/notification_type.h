#ifndef NOTIFICATION_TYPE_H
#define NOTIFICATION_TYPE_H

#include <QString>
#include <QMap>

namespace LogicPlugin {
    /*!
     * \brief Класс, который хранит имеющиеся типы уведомлений, осуществляя функционал
     * добавления новых уведомлений, а также используемый для возвращения названия типа уведомления
     * по его id
     */
    class NotificationType
    {
    public:
        /*!
         * \brief Метод, с помощью которого разработчик может расширить структуру, в которой
         * храняться уведомления и соответсвующие им id
         * \param name - название уведомления, которое требуется добавить
         */
        void addType(const QString &name);

        /*!
         * \brief Метод, возвращающий название уведомления с соответсвующим id
         * \param typeID - id уведомления
         */
        const static QString stringType(uint16_t typeID);

        /*!
         * \brief Метод, проверяющий существует ли в структуре уведомление с соответсвующим id
         * \param typeID - значение, которое требуется проверить (есть ли это значение в структуре)
         */
        static bool isTypeExist(uint16_t typeID);

    private:
        /*!
         * \brief _types - структура, в которой хранятся пары значений (название уведомления и его
         * id)
         */
        static QMap<QString, uint16_t> _types;

        /*!
         * \brief _nTypes - количество уведомлений в структуре (по умолчанию их 4)
         */
        uint16_t _nTypes = 4;
    };
}

#endif // NOTIFICATION_TYPE_H
