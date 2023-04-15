#ifndef GUI_PLUGIN_H
#define GUI_PLUGIN_H

#include "pre-interface.h"

#include <QObject>

class GuiPlugin : public PreInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "ConnectInterface_iid" FILE "plugin_metadata.json")
    Q_INTERFACES(PreInterface)

public:
    GuiPlugin(QObject *parent = 0);
    ~GuiPlugin();

public:
    bool printName();
};

#endif // GUI_PLUGIN_H
