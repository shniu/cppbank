//
// Created by niushaohan on 2018/7/20.
//

#ifndef CPPBANK_RANDOM_HPP
#define CPPBANK_RANDOM_HPP

#include <cstdlib>

// 可以被 C++ 11 的 random 库替代
using std::rand;

/**
 *  生成随机数
 */
class Random {

public:
    /**
     * 生成随机数静态方法
     *
     * @param max 随机数的上限
     * @return 生成的随机数
     */
    static double uniform(double max = 1) {
        return (static_cast<double>(rand()) / RAND_MAX) * max;
    }

    static int uniform(int max = 100) {
        double r = uniform(static_cast<double>(max));
        return static_cast<int>(r);
    }
};

#endif //CPPBANK_RANDOM_HPP
