#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H
#include "Connection/Connection.h"
#include "ConnectionFactory/ConnectionFactory.h"

class ConnectionManager{
public:
    std::shared_ptr<Connection> createConnection(ConnectionFactory& factory){
        auto conn = factory.MakeConnection();
        return conn;
    }
};

#endif // CONNECTIONMANAGER_H

