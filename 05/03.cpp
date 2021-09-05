//
// Created by Veniamin_Arefev on 22.03.2021.
//
#include <iostream>
#include <iterator>
#include <vector>
#include <functional>
#include <algorithm>

template<typename Iterator, typename Function>
void myapply(Iterator start, Iterator end, Function f) {
    while (start != end) {
        f(*start);
        ++start;
    }
}

template<typename Iterator, typename Predict>
std::vector<std::reference_wrapper<typename std::iterator_traits<Iterator>::value_type>>
myfilter2(Iterator start, Iterator end, Predict predict) {
    std::vector <std::reference_wrapper<typename std::iterator_traits<Iterator>::value_type>> vec;
    auto it = vec.begin();
    while (start != end) {
        if (predict(*start)) {
            it = vec.insert(it, *start);
            ++it;
        }
        ++start;
    }
    return vec;
}





