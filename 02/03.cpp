//
// Created by Veniamin_Arefev on 20.02.2021.
//
#include <iostream>

class C {
public:
    C(const C *pC) {}

    friend C operator+(const int b, const C &y) {
        return C();
    }

    friend int operator+(const C &x, const C * y) {
        return 1;
    }

    friend int operator~(const C &x) {
        return 1;
    }

    friend C operator++(const C &x) {
        return 1;
    }

    friend int operator *(const C &x, C *y) {
        return 1;
    }

    C() {};

    C(double d) {}

//    C(int b) {};

    C(const C &v1, int b) {}


};

