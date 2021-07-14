#include "UDPSender.h"

UDPSender::UDPSender()
{

}

void UDPSender::open(){
    m_sockFD = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(m_sockFD == -1){
        perror("UDPListener Socket error");
    }
    //u_int yes = 1;
    //setsockopt(m_sockFD, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
//    i = 10;
//    cout << "UDPListener opening ..\n";
//    cout << "i = " << i << "\n";
}

void UDPSender::connect(){
    memset((char *)&m_sockInAddr, 0, sizeof(m_sockInAddr));
    addr_size = sizeof(m_sockInAddr);
    m_sockInAddr.sin_family = AF_INET;
    m_sockInAddr.sin_port = htons(m_port);
    m_sockInAddr.sin_addr.s_addr = inet_addr(m_ip.c_str());

}

int UDPSender::sendData(vector<unsigned char> data, int port, string addrSend){
    if(addrSend != ""){
        m_ip = addrSend;
        m_sockInAddr.sin_addr.s_addr = inet_addr(addrSend.c_str());
    }
    if(port != -1){
        m_port = port;
        m_sockInAddr.sin_port = htons(m_port);
    }
    int nBytes = sendto(m_sockFD, data.data(), data.size(), 0,
                        (struct sockaddr *)&m_sockInAddr, addr_size);
    return nBytes;
}

vector<unsigned char> UDPSender::recvData(){
    memset((char*)&m_sockInAddr, 0, sizeof(m_sockInAddr));
    addr_size = sizeof(m_sockInAddr);
    vector<unsigned char> result;
    unsigned char buffer[2048];
    int nBytes = recvfrom(m_sockFD, buffer, sizeof(buffer), 0,
                          (struct sockaddr *)&m_sockInAddr, &addr_size);

    if(m_sockInAddr.sin_addr.s_addr != inet_addr(m_ip.c_str())){
        m_ip = string(inet_ntoa(m_sockInAddr.sin_addr));
    }
    if(nBytes < 0){
        printf("\nUDPListener received error = %d", errno);
    }
    if(nBytes > 0 && nBytes <= sizeof(buffer)){
        result = vector<unsigned char>(buffer, buffer + nBytes);
    }
    return result;
}

void UDPSender::disconnect(){
    close(m_sockFD);
}

void UDPSender::setSendTimeout(int seconds, int microseconds){
    struct timeval timeout;
    timeout.tv_sec = seconds;
    timeout.tv_usec = microseconds;

    if(setsockopt(m_sockFD, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout,
                  sizeof(timeout)) < 0){
        printf("setsockopt failed %d\n", errno);
    }

}

void UDPSender::setRevTimeout(int seconds, int microseconds){
    struct timeval timeout;
    timeout.tv_sec = seconds;
    timeout.tv_usec = microseconds;

    if(setsockopt(m_sockFD, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout,
                  sizeof(timeout)) < 0){
        printf("setsockopt failed %d\n", errno);
    }
}

void UDPSender::setAddress(string addr){
    m_ip = addr;
}

void UDPSender::setPort(int port){
    m_port = port;
}

