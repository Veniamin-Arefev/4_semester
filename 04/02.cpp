//
// Created by Veniamin_Arefev on 15.03.2021.
//
#include <vector>

void
process(std::vector<long long> &vec1, long long limit) {
    auto iter = vec1.rbegin();
    unsigned long long offset = 0;
    while (iter != vec1.rend()) {
        if (*iter >= limit) {
            vec1.push_back(*iter);
            ++offset;
            iter = vec1.rbegin() + offset;
        }
        ++iter;
        ++offset;
    }

}
