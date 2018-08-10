//
// Created by niushaohan on 2018/8/9.
//

#include <iostream>
#include "thread_pool.hpp"

using namespace std;

void hello() {
    using namespace std;
    cout << "This is thread hello." << endl;

    /// test for const
    int a1 = 3;
    int a11 = 5;
    const int a2 = a1;
    // a2 = 2;    /// error, 这个时候不能再对a2做修改了，因为已经成名为const

    int * a3 = &a1;  /// 把a1的地址给到a3
    // a3 = &a11;   /// ok
    *a3 = 10;
    const int * a4 = &a1;
    a4 = &a2;
    a4 = &a11;
    // *a4 = 4;  /// error, 不能改变a4指向的数据，指向的数据是个常量不可修改
    int * const a5 = &a1;
    // a5 = &a11;   /// error
    // a5 = &a2;    /// error, 指针本身是常量，不能指向其他内存地址
    *a5 = 10;   /// 指向的数据是可以修改的，说明是一个指针常量，不能指向其他地址

    int const * const a6 = &a1;
    const int * const a7 = &a1;   /// 这两种方式是等价的

}

void test_const(const int * num) {
    /// pass
    // *num = 10;  /// error
}

/// --- above is test, please ignore

// switch active thread
bool MetaThreadPool::SwitchActiveThread() {
    // TODO(@shniu): implements the function
    cout << thread_num_ << endl;
    return true;
}

MetaThreadPool::MetaThreadPool(int thread_num) {
    thread_num_ = thread_num;
}

MetaThreadPool::~MetaThreadPool() {
    // do nothing
}
