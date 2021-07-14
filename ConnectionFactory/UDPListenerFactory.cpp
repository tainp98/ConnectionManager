#include "UDPListenerFactory.h"

UDPListenerFactory::UDPListenerFactory()
{

}

std::shared_ptr<Connection> UDPListenerFactory::MakeConnection(){
    return std::make_shared<UDPListener>();
}

