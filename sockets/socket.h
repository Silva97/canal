#ifndef _SOCKET_H
#define _SOCKET_H

#if _WIN32
    #include <winsock2.h>
    WSADATA wsa_data;

    #define socket_start() {                  \
        WSAStartup(MAKEWORD(2, 0), &wsa_data); \
    }
    #define socket_stop() { \
        WSACleanup();        \
    }
    #define socket_close(s){ \
        closesocket(s);       \
    }
#else
    #include <sys/socket.h>
    #include <sys/types.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <unistd.h>

    #define socket_start()
    #define socket_stop()
    #define socket_close(s){ \
        close(s);             \
    }
#endif

#define SADDR struct sockaddr_in

int socket_create(SADDR sock, int type, int port);
int socket_wait(int socket, SADDR addr);
int socket_read(int socket, char *buff, int size);
int socket_send(int socket, char *buff, int size);


#endif