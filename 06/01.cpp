//
// Created by Veniamin_Arefev on 04.05.2021.
//

#include <iostream>
#include <cinttypes>
#include <climits>
#include <iomanip>


int main() {

    int32_t w1, w2, total = 0, likes = 0;
    std::cin >> w1 >> w2;

    uint32_t temp;
    while (std::cin >> temp) {
        total += sizeof(temp) * CHAR_BIT;
        for (size_t i = 0; i < sizeof(temp) * CHAR_BIT; ++i) {
            likes += temp & 1;
            temp /= 2;
        }
    }

    std::cout << std::fixed << std::setprecision(1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1) //10
            << -1 + (1 + 1) * (likes - std::min(likes, w2)) / (double) total << ' '
            << -1 + (1 + 1) * (likes + std::min(total - likes, w1)) / (double) total << std::endl;

}