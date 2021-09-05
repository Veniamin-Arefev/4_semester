//
// Created by Veniamin_arefev on 10.02.2021.
//
#include <iostream>

class A {
private:
    int sum;
    bool isLastSum;

public:

    A() {
        int b;
        std::cin >> b;
        isLastSum = false;
        this->sum = b;
    }

    A(const A &a) {
        int b;
        std::cin >> b;
        isLastSum = true;
        this->sum = a.sum + b;
    }

    ~A() {
        if (isLastSum) {
            std::cout << sum;
        }
    }
};

