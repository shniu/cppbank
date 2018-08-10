//
// Created by niushaohan on 2018/2/6.
//

#include <iostream>
#include <random>
#include <boost/algorithm/string.hpp>
#include "algo/bubble.cpp"
#include "gtest/gtest.h"
#include "threadpool/thread_pool.hpp"

TEST(metachain, case1) {
    EXPECT_EQ(10, 10);
}


int main(int argc, char **argv) {
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

    MetaThreadPool metaThreadPool(10);
    metaThreadPool.SwitchActiveThread();

    /// unit test
//    testing::InitGoogleTest(&argc, argv);
//    RUN_ALL_TESTS();

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
}

