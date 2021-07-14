#ifndef CONNECTION_H
#define CONNECTION_H
#include <iostream>
#include <vector>

using namespace std;
class Connection{
public:
    virtual void open() = 0;
    virtual void connect() = 0;
    virtual int sendData(vector<unsigned char> data, int port = -1, string addrSend = "") = 0;
    virtual vector<unsigned char> recvData() = 0;
    virtual void disconnect() = 0;
    virtual void setSendTimeout(int seconds, int microseconds) = 0;
    virtual void setRevTimeout(int seconds, int microseconds) = 0;
    virtual void setAddress(string addr) = 0;
    virtual void setPort(int port) = 0;
    virtual ~Connection(){}
};


#endif // CONNECTION_H

