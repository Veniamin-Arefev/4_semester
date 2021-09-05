//
// Created by Veniamin_Arefev on 15.03.2021.
//
#include <cinttypes>
#include <vector>


void
process(const std::vector<uint64_t> &vec1, std::vector<uint64_t> &vec2, uint64_t step) {
    auto vec1_iter = vec1.begin();
    auto vec2_iter = vec2.rbegin();
    if (vec2_iter == vec2.rend()) {
        return;
    }
    uint64_t mystep = step;
    while (vec1_iter != vec1.end()) {
        if (mystep != step) {
            mystep++;
        } else {
            mystep = 1;
            *vec2_iter += *vec1_iter;

            if (vec2_iter == vec2.rend()) {
                break;
            }
            vec2_iter++;
        }
        vec1_iter++;
    }
}