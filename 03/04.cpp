//
// Created by Veniamin_Arefev on 01.03.2021.
//

#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"

enum {
    COMPLEX_INDEX = 1,
    RADIUS_INDEX = 2,
    N_INDEX = 3,
    FUNCTION_INDEX = 4
};

int main(int argc, char **args) {
    numbers::complex z = numbers::complex(args[COMPLEX_INDEX]);
    double rad = strtod(args[RADIUS_INDEX], nullptr);
    long n = strtol(args[N_INDEX], nullptr, 0);
    std::vector<std::string> stack;
    if (true) {
        int i = FUNCTION_INDEX; // 4+ is function
        while (i != argc) {
            stack.push_back(args[i]);
            i++;
        }
    }
    const double step = (M_PI + M_PI) / n;
    numbers::complex cur_comp = numbers::complex(z.re() + rad, z.im());
    numbers::complex sum;
    for (int i = 1; i <= n; ++i) {
        numbers::complex new_comp = numbers::complex(z.re() + rad * cos(i * step), z.im() + rad * sin(i * step));
        sum += eval(stack, cur_comp) * (new_comp - cur_comp);
        cur_comp = new_comp;
    }
    std::cout << sum.to_string() << std::endl;
}