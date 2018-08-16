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

void base_usage_1() {
    std::string str = "123456";
    // 相等为1，不等为0
    printf("%d", str == "123456");
    // 相等为0，不等非0
    printf("%d", str.compare("123456"));

    const char *p = str.data();
    char *pp = const_cast<char *>(str.data());

    const char *w2 = str.c_str();

    char w3[50];
    str.copy(w3, 5, 0);
    *(w3 + 5) = '\0';

    const char *char2str = "000000";
    std::string ss = char2str;

    std::string a2s = "dagah";
    char aa[8];
    int i;
    for( i=0; i<a2s.length(); i++)
        aa[i] = a2s[i];
    aa[i] = '\0';
    printf("%s\n",p);
}

void base_usage_2() {

}
