//
// Created by Veniamin_Arefev on 15.03.2021.
//
#include <vector>
#include <algorithm>
#include <iostream>

void
process(const std::vector<int> &vec1, std::vector<int> &vec2) {
    if (vec2.empty()) {
        return;
    }
    auto positions = vec1;
    std::sort(positions.begin(), positions.end());
    auto last = std::unique(positions.begin(), positions.end());
    positions.erase(last, positions.end());
    auto iter = positions.rbegin();
    unsigned int offset = 0;
    while (iter != positions.rend()) {
        if (*iter >= 0 && ((size_t)*iter) < vec2.size()) {
            *(vec2.begin()+*iter) = INT32_MAX;
            ++offset;
        }
        ++iter;
    }
    std::sort(vec2.begin(),vec2.end());
    vec2.erase(vec2.end()-offset,vec2.end());
}
