//
// Created by Veniamin_Arefev on 22.03.2021.
//
#include <vector>
#include <algorithm>
#include <iostream> // useful

template<typename Iter1, typename Iter2>
Iter2
myremove(Iter1 begin1, Iter1 end1, Iter2 begin2, Iter2 end2)
{
    std::vector<unsigned int> vec;

    while (begin1 != end1) {
        if (*begin1 >= 0) {
            vec.push_back(*begin1);
        }
        ++begin1;
    }
    vec.push_back(INT32_MAX);

    std::sort(vec.begin(), vec.end());
    auto last = std::unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());

    auto iter = vec.begin();
    auto swap_pos = begin2;
    unsigned int offset = 0;
    for (auto cont_iter = begin2; cont_iter != end2; ++cont_iter, ++offset) {
        while (*iter < offset) {
            ++iter;
        }
        if (*iter != offset) {
            std::iter_swap(swap_pos, cont_iter);
            ++swap_pos;
        }
    }
    return swap_pos;
}
