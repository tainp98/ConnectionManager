#include <iostream>
#include <thread>
#include "ConnectionManager.h"
#include "ConnectionFactory/UDPListenerFactory.h"
#include "ConnectionFactory/UDPSenderFactory.h"
#include "Connection/UDPListener.h"
#include "Connection/UDPSender.h"
#include "Packet/EyephoenixProtocol.h"
#include "Packet/KLV.h"
#include "Packet/utils.h"
#include <signal.h>


#define STOP 0
#define RUNNING 1
int state = RUNNING;

typedef std::shared_ptr<Connection> connection;
using namespace std;
void print(connection p){
    p->open();
}

void signal_handler(int sig_num){
    if(sig_num == SIGINT){
        state = STOP;
    }
}

void readConfig(connection udpSend, connection udplisten);
void checkConnection(connection udpSend, connection udplisten);
void CloseConnection(connection udpSend, connection udplisten);
int main()
{
    signal(SIGINT, signal_handler);
    cout << "Hello World!" << endl;
    ConnectionManager cm;
    UDPListenerFactory udpListener;
    UDPSenderFactory udpSender;
    connection UDPListen = cm.createConnection(udpListener);
    connection UDPSend = cm.createConnection(udpSender);

    readConfig(UDPSend, UDPListen);
    checkConnection(UDPSend, UDPListen);
    vector<byte> dataSend;
    while(state){
        while(getchar() != 115);
        data_type scan = 1;
        vector<byte> data = Utils::toByte<data_type>(scan);
        key_type key = (key_type)EyePhoenixProtocol::SetPanScan;
        pair<key_type, vector<byte>> p(key, data);
        KLV packet(key, data);
        dataSend = packet.encode();
        printf("\nStarting Sending Signal Scan to MC");
        UDPSend->sendData(dataSend);
    }

//    std::thread sender(&Connection::sendData, UDPSend, data, -1, "");
//    std::thread listener(&Connection::recvData, UDPListen);
//    sender.join();
//    listener.join();
    CloseConnection(UDPSend, UDPListen);
    return 0;
}

void readConfig(connection udpSend, connection udplisten){
    udpSend->open();
    udpSend->setAddress("192.168.1.131");
    udpSend->setPort(18001);

    udplisten->open();
    udplisten->setAddress("192.168.1.123");
    udplisten->setPort(9877);
}
void checkConnection(connection udpSend, connection udplisten){
    udpSend->connect();

    udplisten->connect();
}

void CloseConnection(connection udpSend, connection udplisten){
    udpSend->disconnect();

    udplisten->disconnect();
}

