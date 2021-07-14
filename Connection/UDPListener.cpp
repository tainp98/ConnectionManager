#include "UDPListener.h"

UDPListener::UDPListener()
{

}

void UDPListener::open(){
    m_sockFD = socket(AF_INET, SOCK_DGRAM, 0);
    if(m_sockFD == -1){
        perror("UDPListener Socket error");
    }
    u_int yes = 1;
    setsockopt(m_sockFD, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
//    i = 10;
//    cout << "UDPListener opening ..\n";
//    cout << "i = " << i << "\n";
}

void UDPListener::connect(){
    SOCKADDR_IN host;
    host.sin_family = AF_INET;
    host.sin_port = htons(m_port);
    host.sin_addr.s_addr = INADDR_ANY;
    /*Bind socket with address struct */
    int Res = ::bind(m_sockFD, (struct sockaddr *) &host, sizeof(host));
    if(Res == -1){
        printf("UDPListener socket bind failed %d\n", errno);
    }else{
        printf("Listen data from port: %d\n", m_port);
    }

}

int UDPListener::sendData(vector<unsigned char> data, int port, string addrSend){
    if(addrSend != ""){
        m_ipSend = addrSend;
        m_sockInAddr.sin_addr.s_addr = inet_addr(addrSend.c_str());
    }
    if(port != -1){
        m_port = port;
        m_sockInAddr.sin_port = htons(m_port);
    }
    addr_size = sizeof(m_sockInAddr);
    int nBytes = sendto(m_sockFD, data.data(), data.size(), 0,
                        (struct sockaddr *)&m_sockInAddr, addr_size);
    return nBytes;
}

vector<unsigned char> UDPListener::recvData(){
    memset((char*)&m_sockInAddr, 0, sizeof(m_sockInAddr));
    addr_size = sizeof(m_sockInAddr);
    vector<unsigned char> result;
    unsigned char buffer[2048];
    int nBytes = recvfrom(m_sockFD, buffer, sizeof(buffer), 0,
                          (struct sockaddr *)&m_sockInAddr, &addr_size);

    if(m_sockInAddr.sin_addr.s_addr != inet_addr(m_ipSend.c_str())){
        m_ipSend = string(inet_ntoa(m_sockInAddr.sin_addr));
    }
    if(nBytes < 0){
        printf("\nUDPListener received error = %d", errno);
    }
    if(nBytes > 0 && nBytes <= sizeof(buffer)){
        result = vector<unsigned char>(buffer, buffer + nBytes);
        cout << "received data \n";
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << "\n";
        }
    }

    return result;
}

void UDPListener::disconnect(){
    close(m_sockFD);
}

void UDPListener::setSendTimeout(int seconds, int microseconds){
    struct timeval timeout;
    timeout.tv_sec = seconds;
    timeout.tv_usec = microseconds;

    if(setsockopt(m_sockFD, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout,
                  sizeof(timeout)) < 0){
        printf("setsockopt failed %d\n", errno);
    }

}

void UDPListener::setRevTimeout(int seconds, int microseconds){
    struct timeval timeout;
    timeout.tv_sec = seconds;
    timeout.tv_usec = microseconds;

    if(setsockopt(m_sockFD, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout,
                  sizeof(timeout)) < 0){
        printf("setsockopt failed %d\n", errno);
    }
}

void UDPListener::setAddress(string addr){
    m_ipSend = addr;
}

void UDPListener::setPort(int port){
    m_port = port;
}


