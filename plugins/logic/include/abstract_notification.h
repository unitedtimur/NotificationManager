#ifndef ABSTRACT_NOTIFICATION_H
#define ABSTRACT_NOTIFICATION_H

#include "logic_plugin_export.h"
#include "notification_type.h"

#include <QString>
#include <QObject>

namespace LogicPlugin {
    /*!
     * \brief Класс, от которого могут наследоваться юзеры библиотеки, чтобы создать новый класс
     * уведомления, если потребуется расширить функционал
     */
    class LOGIC_PLUGIN_EXPORT AbstractNotification: public QObject
    {
    public:
        /*!
         * \brief AbstractNotification конструктор, инициализирующий параметры
         * \param title - строка, в которой храниться название уведомления
         * \param description - строка, в которой храниться более подробное описание уведомления
         * \param type - тип уведомления
         */
        explicit AbstractNotification(QString title, QString description, int type);
        ~AbstractNotification() = default;

        LogicPlugin::NotificationType addType (const QString &name);

        /*!
         * \brief Геттеры для приватных полей класса
         */
        const QString Title();
        const QString Description();
        const int Type();
        //LogicPlugin::NotificationType getType();

        /*!
         * \brief Сеттеры для приватных полей класса
         */
        void setTitle(QString title);
        void setDescription(QString description);
        void setType(int);


    private:
        QString _title;
        QString _description;
        int _type;
    };
}

#endif // ABSTRACT_NOTIFICATION_H
