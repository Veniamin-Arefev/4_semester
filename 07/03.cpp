//
// Created by Veniamin_Arefev on 05.04.2021.
//
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>

//#include "02.cpp"

bool my_comp(const Figure *f1, const Figure *f2) {
    return f1->get_square() < f2->get_square();
}

int main() {
    std::string input_str;
    std::vector<Figure *> mas;
    while (getline(std::cin, input_str)) {
        std::stringstream ss(input_str);
        char type;
        ss >> type;
        double d1, d2;
        std::ostringstream s1;
        switch (type) {
            case 'R':
                ss >> d1;
                ss >> d2;
                s1 << d1 << " " << d2;
                mas.push_back(Rectangle::make(s1.str()));
                break;
            case 'S':
                ss >> d1;
                s1 << d1;
                mas.push_back(Square::make(s1.str()));
                break;
            case 'C':
                ss >> d1;
                s1 << d1;
                mas.push_back(Circle::make(s1.str()));
                break;
            default:
                throw "Unsupported string literal";
        }
    }
    stable_sort(mas.begin(), mas.end(), my_comp);
    for (const auto fig : mas) {
        std::cout << fig->to_string() << std::endl;
    }
    for (auto iter = mas.begin(); iter != mas.end(); ++iter) {
        delete *iter;
    }
    mas.clear();
}