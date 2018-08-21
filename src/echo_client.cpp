//
// Created by niushaohan on 2018/8/20.
//

#ifndef FLUENTCPP_IM_CLIENT_HPP
#define FLUENTCPP_IM_CLIENT_HPP

#include <cstdio>
#include <sys/socket.h>
#include <netdb.h>
#include <cstdlib>
#include <arpa/inet.h>
#include <strings.h>
#include <zconf.h>

#define MAXDATASIZE 1000

namespace echo_client {

    int open_clientfd(in_addr_t domain, in_addr_t port) {
        int client_fd;

        if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            printf("socket error");
            return -1;
        }

        // connect
        struct sockaddr_in server_addr;
        bzero((char *) &server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = domain;
        if (connect(client_fd, (struct sockaddr *) &server_addr, sizeof(struct sockaddr)) == -1) {
            printf("connect error");
            return -1;
        }

        printf("Connect server succeed!");

        int recvbytes;
        int sendbytes;
        int len;
        char buf[MAXDATASIZE];

        if ((recvbytes = static_cast<int>(recv(client_fd, buf, MAXDATASIZE, 0))) == -1) {
            printf("recv error");
            return -1;
        }

        buf[recvbytes] = '\0';
        printf("Received: %s", buf);
        close(client_fd);
        return 0;
    }

    int main(int argc, char** argv) {
        // Params valid
        if (argc < 3) {
            printf("* params not valid, must be provided the host and the port");
            return -1;
        }

        // struct hostent * he = gethostbyname(*(argv + 2));
        in_addr_t domain = inet_addr(*(argv + 2));
        auto port = static_cast<in_port_t>(atoi(*(argv + 3)));

        return open_clientfd(domain, port);
    }

}

#endif //FLUENTCPP_IM_CLIENT_HPP
