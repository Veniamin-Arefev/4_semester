//
// Created by Veniamin_Arefev on 12.04.2021.
//
#include <algorithm>
#include <cinttypes>

int64_t min3(int64_t a, int64_t b, int64_t c) {
    return std::min(a, std::min(b, c));
}

template<typename T>
class Coord {
public:
    typedef T value_type;
    T row, col;

    Coord(const T &r = T(), const T &c = T()) : row(r), col(c) {}
};

template<typename T>
typename T::value_type dist(const T &range, const T &p1, const T &p2) {
    typename T::value_type d1, d2;
    d1 = min3(abs(p2.row - p1.row), p1.row + range.row - p2.row, p2.row + range.row - p1.row);
    d2 = min3(abs(p2.col - p1.col), p1.col + range.col - p2.col, p2.col + range.col - p1.col);
    return std::max(d1, d2);
}
