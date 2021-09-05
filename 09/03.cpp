//
// Created by Veniamin_Arefev on 19.04.2021.
//
#include <iostream>

class S {
    bool init = false;
    bool error = false;
public:
    int sum = 0;
    S() : init(true) {
        int a;
        if (std::cin >> a) {
            sum = a;
            while (std::cin >> a) {
                sum += a;
            }
        } else {
            init = false;
        }
    }

    operator bool() {
        return false;
    }

    ~S() {
        if (init) {
            std::cout << sum << std::endl;
        }
    }
};

//using namespace std;
//
//void func(S v) {
//    if (v) {
//        func(move(v));
//    }
//}
//
//int main() {
//    func(S());
//}

