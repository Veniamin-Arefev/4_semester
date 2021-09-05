//
// Created by Veniamin_arefev on 10.02.2021.
//
#include <iostream>
#include <cinttypes>
#include <climits>

int main() {
    uint16_t in;
    uint32_t i = 0;
    uint32_t scrap;
    uint32_t temp = 0;
    while (true) {
        if (i == 0) {
            std::cin >> std::hex >> scrap;
        }
        std::cin >> std::hex >> in;
        if (std::cin.fail()) {
            break;
        }
        temp = (temp << sizeof(uint8_t)*CHAR_BIT) + in;
        if (i % 4 == 3)  {
            std::cout << std::dec << temp << std::endl;
            temp = 0;
        }

        i = (i + 1) % 16;
    }
}