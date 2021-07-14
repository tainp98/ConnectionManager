#include "UDPSenderFactory.h"

UDPSenderFactory::UDPSenderFactory()
{

}

std::shared_ptr<Connection> UDPSenderFactory::MakeConnection(){
    return std::make_shared<UDPSender>();
}

