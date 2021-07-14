#ifndef UDPLISTENERFACTORY_H
#define UDPLISTENERFACTORY_H
#include "ConnectionFactory.h"
#include "Connection/UDPListener.h"

class UDPListenerFactory : public ConnectionFactory
{
public:
    UDPListenerFactory();
    virtual std::shared_ptr<Connection> MakeConnection();

private:

};

#endif // UDPLISTENERFACTORY_H
