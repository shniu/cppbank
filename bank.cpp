//
// Created by niushaohan on 2018/7/19.
//
#include <iostream>
#include <cstdlib>
#include "bank.hpp"

Bank::Bank(int window_number, int close_time)
        : _queue_number(window_number), _close_time(close_time), _customer_number(0) {
    std::cout << "初始化Bank" << std::endl;
}

Bank::~Bank() {}

void Bank::Simulation() {
    printf("处理业务, %d\n", _queue_number);

    int rand_number = std::rand() % 10;
    std::cout << rand_number << std::endl;

    int rand_number2 = std::rand() % 10;
    std::cout << rand_number2 << std::endl;
}
