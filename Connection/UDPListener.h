#ifndef UDPLISTENER_H
#define UDPLISTENER_H
#include "Connection.h"
#include <iostream>
#include <stdio.h>
#include "../define.h"


using namespace std;

class UDPListener : public Connection
{
public:
    UDPListener();
    virtual void open();
    virtual void connect();
    virtual int sendData(vector<unsigned char> data, int port, string addrSend);
    virtual vector<unsigned char> recvData();
    virtual void disconnect();
    virtual void setSendTimeout(int seconds, int microseconds);
    virtual void setRevTimeout(int seconds, int microseconds);
    virtual void setAddress(string addr);
    virtual void setPort(int port);
public:
    SOCKADDR_IN m_sockInAddr;
    SOCKET m_sockFD;
    socklen_t addr_size;
    string m_ipSend;
    int m_port;
};

#endif // UDPLISTENER_H
