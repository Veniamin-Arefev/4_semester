//
// Created by Veniamin_Arefev on 01.03.2021.
//
//#include "01.cpp"
//#include "02.cpp"
#include <vector>
#include <string>

namespace numbers {
    complex eval(const std::vector<std::string> &args, const complex &z) {
        complex_stack stack;
        for (const auto &str: args) {
            if (str[0] == '(') {
                stack = stack << complex(str);
            } else if (str == "z") {
                stack = stack << z;
            } else if (str == "+" || str == "-" || str == "*" || str == "/") {
                complex z2 = +stack;
                stack = ~stack;
                complex z1 = +stack;
                stack = ~stack;
                if (str == "+") {
                    stack = stack << (z1 + z2);
                } else if (str == "-") {
                    stack = stack << (z1 - z2);
                } else if (str == "*") {
                    stack = stack << (z1 * z2);
                } else if (str == "/") {
                    stack = stack << (z1 / z2);
                }
            } else if (str == "!") {
                stack = stack << +stack;
            } else if (str == ";") {
                stack = ~stack;
            } else if (str == "~") {
                complex temp = ~(+stack);
                stack = (~stack) << temp;
            } else if (str == "#") {
                complex temp = -(+stack);
                stack = (~stack) << temp;
            }
        }
        return +stack;
    }
}
