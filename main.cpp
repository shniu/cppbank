//
// Created by niushaohan on 2018/2/6.
//

#include <iostream>
#include <string>
#include <random>
#include <boost/algorithm/string.hpp>
#include "algo/bubble.cpp"
#include "gtest/gtest.h"
#include "src/thread_pool.hpp"
#include "src/io.hpp"
#include "src/ip_conv.hpp"

TEST(metachain, case1) {
    EXPECT_EQ(10, 10);
}


int main(int argc, char **argv) {

    /// Parse command line
    printf("Command line params num: %d\n", argc);
    printf("Command line param: %s\n", *(argv + 1));

    char *action = *(argv + 1);
    if (strcmp(action, "io") == 0) {
        op_file1();
        base_usage_1();
    } else if (strcmp(action, "thread-pool") == 0) {
         MetaThreadPool metaThreadPool(10);
         metaThreadPool.SwitchActiveThread();
    } else if (strcmp(action, "unittest") == 0) {
        testing::InitGoogleTest(&argc, argv);
        RUN_ALL_TESTS();
    } else if (strcmp(action, "ipconv") == 0) {
        const char *ip = "192.168.1.124";
        char * hex = ip_to_hex(ip);
        printf("ip to hex: %s\n", hex);
    }

    /*std::cout << "模拟银行队列" << std::endl;
    Bank b = Bank(1);
    b.Simulation();

    std::cout << Random::uniform(1) << std::endl;
    std::cout << Random::uniform(100.0) << std::endl;
    std::cout << Random::uniform(100) << std::endl;
    std::cout << Random::uniform(100) << std::endl;
    std::cout << Random::uniform(100000) << std::endl;

    // c++ std random
    std::default_random_engine generator;
    std::uniform_int_distribution<int> dis(0, 100);
    for (int i = 0; i < 5; i++) {
        std::cout << dis(generator) << std::endl;
    }

    std::default_random_engine generator2(time(nullptr));
    std::uniform_int_distribution<int> dis2(0, 100);
    // auto dice = std::bind(dis2, generator2);
    */
    // hello();

    /// bubble sort
    /*int n, i, a[100];
    std::cin >> n;
    for (i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    bubble_sort(a, n);
    for (i = 0; i < n; i++) {
        std::cout << a[i] << std::endl;
    }*/

    return 0;
}

