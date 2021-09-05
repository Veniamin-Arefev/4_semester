//
// Created by Veniamin_Arefev on 12.04.2021.
//
#include "iostream"

int main() {
    int m, n;
    std::cin >> m >> n;
    int r1, c1, r2, c2;
    while (std::cin >> r1 >> c1 >> r2 >> c2) {
        int d1, d2;
        d1 = std::min(abs(r2 - r1), std::min(r1 + m - r2, r2 + m - r1));
        d2 = std::min(abs(c2 - c1), std::min(c1 + n - c2, c2 + n - c1));
        std::cout << d1 + d2 << std::endl;
    }
}
