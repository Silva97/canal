/********************
 * Delevoped by Luiz Felipe
 * GitHub: https://github.com/Silva97
 *
 * Date: 02/17/2018
 ********************/

#include "inc/socket.h" // SADDR
#include <stdio.h>
#include <string.h>
#include <errno.h>

int socket_create(SADDR addr, int type, int port){
    int s;
    if((s = socket(AF_INET, type, 0)) == -1){
        printf("Error on create socket on port %d: %s\n", port, strerror(errno));
        return -1;
    }

    addr.sin_family      = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port        = htons(port);
    memset(addr.sin_zero, '\0', sizeof addr.sin_zero);

    if( bind(s, (struct sockaddr *) &addr, sizeof addr) != 0){
        printf("Error on bind socket on port %d: %s\n", port, strerror(errno));
        return -1;
    }

    return s;
}

int socket_wait(int socket, SADDR addr){
    int s;
    int addrsize = sizeof addr;
    if((s = accept(socket, (struct sockaddr *) &addr, &addrsize)) == -1){
        perror("Error on wait for connection on socket");
        return -1;
    }

    return s;
}

int socket_read(int socket, char *buff, int size){
    int r;
    if((r = recv(socket, buff, size, 0)) == -1){
        perror("Error on read data from socket");
        return -1;
    }

    buff[r] = '\0';
    return r;
}

int socket_send(int socket, char *buff, int size){
    int r;
    if(size < 1){
        size = strlen(buff);
    }

    if((r = send(socket, buff, size, 0)) == -1){
        perror("Error on send data for buffer");
        return -1;
    }

    return r;
}