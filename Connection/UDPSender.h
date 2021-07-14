#ifndef UDPSENDER_H
#define UDPSENDER_H
#include "Connection.h"
#include "../define.h"
#include <iostream>
#include <stdio.h>
using namespace std;

class UDPSender : public Connection
{
public:
    UDPSender();
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
    //int slen;
    string m_ip;
    int m_port;
};

#endif // UDPSENDER_H
