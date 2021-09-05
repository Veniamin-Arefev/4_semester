//
// Created by Veniamin_Arefev on 19.04.2021.
//
#include <iostream>
#include <cinttypes>

class S {
public:
    int64_t sum;

    S(int64_t a) : sum(a) {

    }
};

void func(int64_t a, int64_t b, int64_t k) {
    if (k == 0) {
        throw S(a + b);
    } else if (b == 1) {
        throw S(a);
    } else {
        try {
            func(a, b - 1, k);
        }
        catch (S &s) {
            try {
                func(a, s.sum, k - 1);
            }
            catch (S &s) {
                throw;
            }
        }
    }
}


int main() {
    int64_t a, b, k;
    while (std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        }
        catch (S &s) {
            std::cout << s.sum << std::endl;
        }
    }
}
