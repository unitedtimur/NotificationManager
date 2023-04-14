#ifndef GUI_PLUGIN_H
#define GUI_PLUGIN_H

#include "connect_interface.h"

#include <QObject>

class GuiPlugin : public QObject, public ConnectInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "ConnectInterface_iid" FILE "plugin_metadata.json")
    Q_INTERFACES(ConnectInterface)

public:
    GuiPlugin(QObject *parent = 0);
    ~GuiPlugin();
    QString name();

public:
    virtual bool printDocument(QString strDoc);
};

#endif // GUI_PLUGIN_H
