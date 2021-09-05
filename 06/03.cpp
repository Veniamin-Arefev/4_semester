//
// Created by Veniamin_Arefev on 10.05.2021.
//

#include <vector>
#include <iostream>
#include <cinttypes>
#include <map>


int main() {
    constexpr uint64_t mod = 4294967161u;

    std::map<uint64_t, std::map<uint64_t, uint64_t>> mas1;
    std::map<uint64_t, std::map<uint64_t, uint64_t>> mas2;

    uint64_t row, column, value;
    //read and transpose matrix
    while (std::cin >> row >> column >> value) {
        if (row == 0 && column == 0 && value == mod) {
            break;
        }
        mas1[column][row] = value % mod;
    }

    while (std::cin >> row >> column >> value) {
        for (auto &row_and_elem: mas1[row]) {

            mas2[row_and_elem.first][column] += ((row_and_elem.second) * value) % mod;
            mas2[row_and_elem.first][column] %= mod;
        }
    }

    for (auto &mas_elem: mas2) {
        for (auto &elem: mas_elem.second) {
            if (elem.second != 0) {
                std::cout << mas_elem.first << " " << elem.first << " " << elem.second << std::endl;
            }
        }
    }

}