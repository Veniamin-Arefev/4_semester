//
// Created by Veniamin_Arefev on 01.03.2021.
//
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

namespace numbers {
    class complex {
        double real;
        double imag;
    public:
        complex(double real = 0, double imag = 0) {
            this->real = real;
            this->imag = imag;
        }

        explicit complex(const std::string &str) {
            int separator = str.find(',');
//            std::cout << separator << std::endl;
//            std::cout << str.length() << std::endl;
            std::string re = str.substr(1, separator - 1);
            std::string im = str.substr(separator + 1, str.length() - separator - 1 - 1);
//            std::cout << re << std::endl;
//            std::cout << im << std::endl;
            real = std::stod(re);
            imag = std::stod(im);
        }

        double re() const {
            return real;
        }

        double im() const {
            return imag;
        }

        double abs2() const {
            return real * real + imag * imag;
        }

        double abs() const {
            return sqrt(abs2());
        }

        std::string to_string() const {
            char *str = new char[10000];
            sprintf(str, "(%.10g,%.10g)", real, imag);
            std::string output = std::string(str);
            delete[] str;
            return output;
        }

        complex &operator+=(const complex comp) {
            real += comp.real;
            imag += comp.imag;
            return *this;
        }

        complex &operator-=(const complex comp) {
            real -= comp.real;
            imag -= comp.imag;
            return *this;
        }

        complex &operator*=(const complex comp) {
            double newreal = real * comp.real - imag * comp.imag;
            imag = real * comp.imag + imag * comp.real;
            real = newreal;
            return *this;
        }

        complex &operator/=(const complex comp) {
            double divisor = comp.real * comp.real + comp.imag * comp.imag;
            double newreal = real * comp.real + imag * comp.imag;
            imag = imag * comp.real - real * comp.imag;
            imag /= divisor;
            real = newreal / divisor;
            return *this;
        }

        friend complex operator+(const complex left, const complex right) {
            return complex(left.real + right.real, left.imag + right.imag);
        }

        friend complex operator-(const complex left, const complex right) {
            return complex(left.real - right.real, left.imag - right.imag);
        }

        friend complex operator*(const complex left, const complex right) {
            return complex(left.real * right.real - left.imag * right.imag,
                    left.real * right.imag + left.imag * right.real);
        }

        friend complex operator/(const complex left, const complex right) {
            double divisor = right.real * right.real + right.imag * right.imag;
            return complex((left.real * right.real + left.imag * right.imag) / divisor,
                    (left.imag * right.real - left.real * right.imag) / divisor);
        }

        complex &operator~() const {
            auto *comp = new complex(real, -imag);
            return *comp;
        }

        complex &operator-() const {
            auto *comp = new complex(-real, -imag);
            return *comp;
        }
    };
};
