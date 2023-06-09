#include "history_model.h"
#include "qdatetime.h"

namespace LogicPlugin {
    HistoryModel::HistoryModel(QObject *parent) : QSqlTableModel(parent)
    {
        setTable("notification");
        QDate myDate = QDate::currentDate();
        QString myDateString = myDate.toString("yyyy-MM-dd");
        setFilter(QString("Date LIKE '%1'").arg(myDateString));
        select();
    }

    QHash<int, QByteArray> HistoryModel::roleNames() const
    {
        QHash<int, QByteArray> roles;
        roles[TitleRole] = "title";
        roles[MessageRole] = "message";
        roles[TypeRole] = "type";
        roles[DateRole] = "date";
        roles[TimeRole] = "time";
        roles[ColorRole] = "hexcolor";
        return roles;
    }

    QVariant HistoryModel::data(const QModelIndex &index, int role) const
    {
        if (role < Qt::UserRole)
            return QSqlTableModel::data(index, role);

        QSqlRecord record = QSqlTableModel::record(index.row());
        switch (role) {
        case TitleRole:
            return record.value("Title");
        case MessageRole:
            return record.value("Message");
        case TypeRole:
            return record.value("Type");
        case DateRole:
            return record.value("Date");
        case TimeRole:
            return record.value("Time");
        case ColorRole:
            return record.value("Color");
        default:
            return QVariant();
        }
    }
    void HistoryModel::selectByDate(const QString &dateStr)
    {
        QString argument = dateStr + '%';
        setFilter(QString("Date='%1'").arg(argument));
        select();
    }
}
