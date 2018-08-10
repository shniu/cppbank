//
// Created by niushaohan on 2018/8/9.
//

#include <iostream>


void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

/// Bubble sort interface
void bubble_sort(int *p, int length) {

    for (int i = 0; i < length; i++) {
        for (int j = length - 1; j > i; j--) {
            if (p[j] > p[j - 1]) {
                swap(p[j], p[j - 1]);
                std::cout << p[j] << std::endl;
            }
        }
    }
}
