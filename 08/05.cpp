//
// Created by Veniamin_Arefev on 12.04.2021.
//

#include <iostream>
#include <complex>
#include <vector>
#include <array>

namespace Equations {
    template<typename T>
    std::pair<bool, std::vector<T>> quadratic(const std::array<T, 3> v) {
        std::vector<T> roots;
        if (norm(v[2]) == 0) { // a == 0
            if (norm(v[1]) == 0) { // b == 0
                if (norm(v[0]) == 0) { // c == 0
                    return std::pair(false, roots);
                } else {
                    return std::pair(true, roots);
                }
            } else {
                roots.push_back(-v[0]/v[1]);
                return std::pair(true, roots);
            }
        } else {
            T com4 = T(4.0);
            T dis = v[1] * v[1] - v[2] * v[0] * com4;
            dis = pow(dis,0.5);
            T com2 = T(2.0);
            roots.push_back((-v[1] + dis)/com2/v[2]);
            roots.push_back((-v[1] - dis)/com2/v[2]);
            return std::pair(true, roots);
        }
    }

}