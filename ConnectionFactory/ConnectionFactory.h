#ifndef CONNECTIONFACTORY_H
#define CONNECTIONFACTORY_H
#include "Connection/Connection.h"
#include "../define.h"
#include <memory>

class ConnectionFactory{
public:
    virtual std::shared_ptr<Connection> MakeConnection() = 0;
    virtual ~ConnectionFactory(){

    }

};

#endif // CONNECTIONFACTORY_H

