#ifndef IMODEL_H
#define IMODEL_H

#include "logic_plugin_export.h"

#include <QAbstractListModel>
#include <QPointer>
#include <QTimerEvent>

namespace LogicPlugin {

    class LOGIC_PLUGIN_EXPORT IModel : public QAbstractListModel
    {
    public:
        IModel();
    };
}
#endif // IMODEL_H
