#include "history_model.h"
namespace LogicPlugin{
HistoryModel::HistoryModel(QObject *parent = nullptr)
    : QSqlTableModel(parent)
{
    setTable("notification");
    select();
}

QHash<int, QByteArray> HistoryModel::roleNames() const override
{
    QHash<int, QByteArray> roles;
    roles[TitleRole] = "title";
    roles[MessageRole] = "message";
    roles[TypeRole] = "type";
    roles[DateRole] = "date";
    return roles;
}

QVariant HistoryModel::data(const QModelIndex &index, int role = Qt::DisplayRole) const override
{
    if (role < Qt::UserRole)
        return QSqlTableModel::data(index, role);

    QSqlRecord record = QSqlTableModel::record(index.row());
    switch (role) {
    case TitleRole:
        return record.value("Title");
    case MessageRole:
        return record.value("Description");
    case TypeRole:
        return record.value("Type");
    case DateRole:
        return record.value("Date");
    default:
        return QVariant();
    }
}
void HistoryModel::selectByDate(const QString& dateStr)
{
    setFilter(QString("Date='%1'").arg(dateStr));
    select();
}
}
