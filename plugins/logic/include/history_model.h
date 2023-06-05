#ifndef HISTORY_MODEL_H
#define HISTORY_MODEL_H
#include <QSqlTableModel>
#include <QSqlRecord>
namespace LogicPlugin {
    class HistoryModel final : public QSqlTableModel
    {
        Q_OBJECT
    public:
        enum Roles
        {
            TitleRole = Qt::UserRole + 1,
            MessageRole,
            TypeRole,
            DateRole
        };

        HistoryModel(QObject *parent = nullptr);
        QHash<int, QByteArray> roleNames() const override;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        Q_INVOKABLE void selectByDate(const QString &dateStr);
    };
}

#endif // HISTORY_MODEL_H
