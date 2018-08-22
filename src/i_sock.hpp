//
// Created by niushaohan on 2018/8/22.
//

#ifndef FLUENTCPP_I_SOCK_HPP
#define FLUENTCPP_I_SOCK_HPP

#include <sys/socket.h>
#include <cstdio>

// i_socket
// Usage: int fd = i_socket(AF_INET, SOCK_STREAM, 0)
int i_socket(int domain, int type, int protocol) {
    int fd;
    if ((fd = socket(domain, type, protocol)) == -1) {
        perror("socket error");
        // exit when get socket error
        exit(1);
    }
    return fd;
}

// i_bind


#endif //FLUENTCPP_I_SOCK_HPP
