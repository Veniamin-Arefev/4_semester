//
// Created by Veniamin_Arefev on 17.05.2021.
//

#include <vector>

#include <iostream>

enum fig_types { //doesnt use later in code, just for indexing
    UNDEFINED = 0,
    RECTANGLE = 1,
    TRIANGLE = 2
};

class Figure {
    int type; //must not be modified after assignments
public:
    std::vector<int> sides;

    int get_type() const {
        return type;
    }

    Figure(int type) : type(type) {}

    Figure() : type(0) {} // UNDEFINED == 0

    virtual bool equals(const Figure *const pointer) = 0;

    std::vector<int> get_sides() const {
        return sides;
    }

};

class Rectangle : public Figure {
public:
    Rectangle(int a, int b) : Figure(1) { // RECTANGLE == 1
        sides.push_back(a);
        sides.push_back(b);
    }

    bool equals(const Figure *const pointer) override {
        if (pointer == nullptr) {
            return false;
        }
        if (this->get_type() == pointer->get_type()) {
            if (this->get_sides().size() == pointer->get_sides().size()) {
                for (size_t i = 0; i < this->get_sides().size(); ++i) {
                    if (this->get_sides()[i] != pointer->get_sides()[i]) {
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }
};

class Triangle : public Figure {
public:
    Triangle(int a, int b, int c) : Figure(2) { // TRIANGLE == 2
        sides.push_back(a);
        sides.push_back(b);
        sides.push_back(c);
    }

    bool equals(const Figure *const pointer) override {
        if (pointer == nullptr) {
            return false;
        }
        if (this->get_type() == pointer->get_type()) {
            if (this->get_sides().size() == pointer->get_sides().size()) {
                for (size_t i = 0; i < this->get_sides().size(); ++i) {
                    if (this->get_sides()[i] != pointer->get_sides()[i]) {
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }
};

//int main() {
//    Rectangle r1(10, 5), r2(10, 2), r3(10, 5), r4(5, 10);
//    Triangle t1(1, 2, 3);
//    Figure *f = &r1;
//    Rectangle rec(10, 5);
//    Triangle tri(10, 5, 3);
//    Figure *f1 = &rec;
//    Figure *f2 = &tri;
//
//    std::cout << f1->equals(&tri) << std::endl;
//    std::cout << f2->equals(&rec) << std::endl << std::endl;
//
//    std::cout << f->equals(&r2) << std::endl;
//    std::cout << f->equals(&r3) << std::endl;
//    std::cout << f->equals(&r4) << std::endl;
//    std::cout << f->equals(&t1) << std::endl;
//    std::cout << f->equals(nullptr) << std::endl;
//    // 0 1 0 0 0
//}