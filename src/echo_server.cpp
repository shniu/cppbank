//
// Created by niushaohan on 2018/8/20.
//

#ifndef FLUENTCPP_IM_SERVER_HPP
#define FLUENTCPP_IM_SERVER_HPP

#include <cstdlib>
#include <cstdio>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <strings.h>
#include <string.h>
#include <arpa/inet.h>
#include <zconf.h>

#define SERVER_PORT 6666

namespace echo_server {

    int open_listenfd() {
        // fd
        int listenfd;

        if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            printf("* socket error");
            return -1;
        }
        printf("* listen fd: %d\n", listenfd);

        // sockaddr_in
        struct sockaddr_in my_addr;
        my_addr.sin_family = AF_INET;
        my_addr.sin_port = htons(SERVER_PORT);
        my_addr.sin_addr.s_addr = INADDR_ANY;
        bzero(&(my_addr.sin_zero), 8);

        // bind
        if (bind(listenfd, (struct sockaddr *) &my_addr, sizeof(struct sockaddr)) == -1) {
            printf("* bind error");
            return -1;
        }

        // listen
        if (listen(listenfd, 20) == -1) {
            printf("* listen error");
            return -1;
        }

        printf("* Echo server listen port: %d\n", SERVER_PORT);

        int sin_size;
        int client_fd;
        struct sockaddr_in remote_addr;

        while (1) {
            // accept
            sin_size = sizeof(struct sockaddr_in);
            if ((client_fd = accept(listenfd, (sockaddr *) &remote_addr, (socklen_t *)&sin_size)) == -1) {
                perror("* accept error");
                continue;
            }

            printf("* received a connection from %s:%d\n", inet_ntoa(remote_addr.sin_addr), ntohs(remote_addr.sin_port));

            // child process
            if (!fork()) {
                // recv message from the client and then send back to client
                char buf[1000] = {0};
                auto recvbytes = static_cast<int>(recv(client_fd, buf, 1000, 0));
                buf[recvbytes] = '\0';
                printf("* \tmessage is: %s\n", buf);
                char * msg = buf; // "Hello, i'm echo server.";
                if (send(client_fd, msg, static_cast<size_t>(recvbytes), 0) == -1) {
                    printf("* send error");
                }
                close(client_fd);
                exit(0);
            }

            // close(client_fd);
            // while (waitpid(-1, NULL, WNOHANG) > 0);
        }

        return listenfd;
    }

    int main(int argc, char** argv) {
        return open_listenfd();
    }
}

#endif //FLUENTCPP_IM_SERVER_HPP
