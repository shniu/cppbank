//
// Created by niushaohan on 2018/8/16.
//

#include "io.hpp"

void op_file1() {
    int fd1, fd2;
    fd1 = open("/tmp/a.txt", O_RDONLY, 0);
    close(fd1);
    fd2 = open("/tmp/b.txt", O_RDONLY | O_CREAT, 0);
    printf("fd2: %d\n", fd2);
    // close(fd2);
}
