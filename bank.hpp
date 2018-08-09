//
// Created by niushaohan on 2018/7/19.
//

#ifndef CPPBANK_BANK_HPP
#define CPPBANK_BANK_HPP

class Bank {

public:
    explicit Bank(int window_number = 4, int close_time = 8 * 3600);

    ~Bank();

    void Simulation();

private:
    int _queue_number;
    int _close_time;
    int _customer_number;
};

#endif //CPPBANK_BANK_HPP
