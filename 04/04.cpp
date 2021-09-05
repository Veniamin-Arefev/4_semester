//
// Created by Veniamin_Arefev on 15.03.2021.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

struct Sum {
    long double sum{0};

    void operator()(long double n) { sum += n; }
};

int main() {
    std::vector<long double> mas;
    long double temp;
    while (std::cin >> temp) {
        mas.push_back(temp);
    }
    int offset1 = mas.size() * 0.1;
    int cur_mas_size = mas.size() - offset1 - offset1;
    std::sort(mas.begin() + offset1, mas.end() - offset1);
    int offset2 = cur_mas_size * 0.1;
    cur_mas_size -= offset2 + offset2;
    int total_offset = offset1 + offset2;
    long double total_sum = std::for_each(mas.begin() + total_offset, mas.end() - total_offset, Sum()).sum;
    std::cout << std::setprecision(10) << std::fixed << total_sum / cur_mas_size << std::endl;
}
