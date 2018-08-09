//
// Created by niushaohan on 2018/2/6.
//

#include <iostream>
#include <random>
#include <boost/algorithm/string.hpp>
#include "bank.hpp"
#include "random.hpp"

int main(int argc, char **argv) {
    std::cout << "模拟银行队列" << std::endl;
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
}

