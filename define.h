#ifndef DEFINE_H
#define DEFINE_H
// socket
#ifdef _WIN32
    #include <winsock.h>
    #include <windows.h>
    #include <time.h>
    #define PORT        unsigned long
    #define ADDRPOINTER   int*
    struct _INIT_W32DATA
    {
       WSADATA w;
       _INIT_W32DATA() { WSAStartup( MAKEWORD( 2, 1 ), &w ); }
    } _init_once;
#else       /* ! win32 */
    #include <string.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <sys/time.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netdb.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #define PORT        unsigned short
    #define SOCKET    int
    #define HOSTENT  struct hostent
    #define SOCKADDR    struct sockaddr
    #define SOCKADDR_IN  struct sockaddr_in
    #define ADDRPOINTER  unsigned int*
    #define INVALID_SOCKET -1
    #define SOCKET_ERROR   -1
#endif /* _WIN32 */

// oop
#include <iostream>
#include <vector>

using namespace std;

#endif // DEFINE_H

