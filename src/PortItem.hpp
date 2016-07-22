#pragma once

#include <QStandardItem>
#include "TypedItem.hpp"
#include "Types.hpp"
#include "ConfigItem.hpp"

namespace RTT
{
    namespace base
    {
        class OutputPortInterface;
        class InputPortInterface;
    }
}

class PortHandle;

class PortItem
{
protected:
    std::shared_ptr<ItemBase> item;
    TypedItem *nameItem;
    TypedItem *valueItem;

public:
    PortItem(const std::string &name);
    QList<QStandardItem *> getRow();
};


class OutputPortItem : public PortItem
{
    PortHandle *handle;
    RTT::base::InputPortInterface *reader;

public:
    OutputPortItem(RTT::base::OutputPortInterface* port);
    bool updataValue();
};
