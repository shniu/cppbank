//
// Created by niushaohan on 2018/8/9.
//
#pragma once

#ifndef CPPBANK_THREAD_HPP
#define CPPBANK_THREAD_HPP

void hello();  /// just for test

// Base thread pool that has some feature
class BaseThreadPool {
public:
    virtual bool SwitchActiveThread() = 0;
};


// The interface of the thread pool process
// very important
class MetaThreadPool : public BaseThreadPool {

public:
    MetaThreadPool(int thread_num);
    ~MetaThreadPool(void);

public:
    virtual bool SwitchActiveThread();

private:
    int thread_num_;
};

#endif //CPPBANK_THREAD_HPP
