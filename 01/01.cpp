//
// Created by Veniamin_arefev on 10.02.2021.
//
#include <iostream>

class Sum {
private:
    long long sum;

public:
    long long get() const{
        return sum;
    }

    Sum(int a = 0, int b = 0) {
        this->sum = a + b;
    }

    Sum(const Sum &a, int b = 0) {
        this->sum = a.sum + b;
    }
};

