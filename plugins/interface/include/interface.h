#ifndef GUI_PLUGIN_H
#define GUI_PLUGIN_H

#include "pre-interface.h"

#include <QObject>

class GuiPluginTest : public PreInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "ConnectInterface_iid" FILE "plugin_metadata.json")
    Q_INTERFACES(PreInterface)

public:
    virtual bool init() override;
};

#endif // GUI_PLUGIN_H
