//
// Created by niushaohan on 2018/8/20.
//

#include <string.h>
#include <iostream>
#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>
#include "tinyhttp.hpp"

using namespace std;

int tinyhttp::open_clientfd(char *hostname, int port) {
    int clientfd;
    struct hostent *hp;
    struct sockaddr_in serveraddr{};

    if ((clientfd = socket(AF_INET, SOCK_STREAM, 0) < 0)) {
        return -1;
    }

    if ((hp = gethostbyname(hostname)) == nullptr) {
        return -2;
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy(hp->h_addr_list[0],
          (char *) &serveraddr.sin_addr.s_addr, static_cast<size_t>(hp->h_length));
    serveraddr.sin_port = htons(port);

    if (connect(clientfd, (sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        return -1;
    }

    return clientfd;
}

int tinyhttp::open_listenfd(int port) {

    return port;
}

void tinyhttp::main() {
    const int port = 1111;
    // int fd = open_clientfd("", port);
    int listenfd = open_listenfd(port);

}
