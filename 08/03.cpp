//
// Created by Veniamin_Arefev on 12.04.2021.
//
#include <iostream>

namespace Game {
    template<typename T>
    class Coord {
    public:
        typedef T value_type;
        T row, col;

        Coord(const T &r = T(), const T &c = T()) : row(r), col(c) {}
    };

    template<typename T>
    typename T::value_type dist(const T &range, const T &p1, const T &p2) {
        typename T::value_type y1, z1, y2, z2;
        //changes the coordinate system to x,y,z where x == Coord.col
        z1 = p1.row - (p1.col + (p1.col & 1)) / 2;
        z2 = p2.row - (p2.col + (p2.col & 1)) / 2;
        y1 = -p1.col - z1;
        y2 = -p2.col - z2;

        return (std::abs(p1.col - p2.col) + std::abs(y1 - y2) + std::abs(z1 - z2)) / 2;
    }
}
