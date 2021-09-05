//
// Created by Veniamin_Arefev on 29.03.2021.
//
#include <vector>
#include <iostream>
#include <cinttypes>
#include <utility>
#include <map>


int main() {
    const uint64_t mod = 4294967161u;

    std::map<std::pair<uint64_t, uint64_t>, uint64_t> mas;
    uint64_t row, columb, value;
    while (std::cin >> row >> columb >> value) {
        if (mas.count(std::make_pair(row, columb)) != 0) {
            mas[std::make_pair(row, columb)] = (value + mas[std::make_pair(row, columb)]) % mod;
        } else {
            mas[std::make_pair(row, columb)] = value % mod;
        }
    }
    for (auto &elem : mas) {
        if (elem.second != 0) {
            std::cout << elem.first.first << " " << elem.first.second << " " << elem.second << std::endl;
        }
    }
}