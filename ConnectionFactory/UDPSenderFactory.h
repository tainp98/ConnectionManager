#ifndef UDPSENDERFACTORY_H
#define UDPSENDERFACTORY_H
#include "ConnectionFactory/ConnectionFactory.h"
#include "Connection/UDPSender.h"


class UDPSenderFactory : public ConnectionFactory
{
public:
    UDPSenderFactory();
    virtual std::shared_ptr<Connection> MakeConnection();
};

#endif // UDPSENDERFACTORY_H
