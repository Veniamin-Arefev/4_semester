//
// Created by Veniamin_Arefev on 05.04.2021.
//
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>

class Figure {
public:
    virtual double get_square() const = 0;
    virtual std::string to_string() const = 0;
    virtual ~Figure() {}
};

class Rectangle : public Figure {
    double height, width;
public:
    static Rectangle* make(const std::string& str) {
        std::stringstream ss(str);
        double d1, d2;
        ss >> d1;
        ss >> d2;
        return new Rectangle(d1, d2);
    }
    Rectangle(double height, double width): height(height), width(width){}
    virtual double get_square() const { return height*width;}
    virtual ~Rectangle() {}
    virtual std::string to_string() const{return std::to_string(1.0);}
};

class Square : public Figure {
    double side;
public:
    static Square* make(const std::string& str) {
        std::stringstream ss(str);
        double d1;
        ss >> d1;
        return new Square(d1);
    }
    Square(double side): side(side){}
    virtual double get_square() const { return side*side;}
    virtual ~Square() {}
    virtual std::string to_string() const{return std::to_string(side);}
};

class Circle : public Figure {
    double radius;
public:
    static Circle* make(const std::string& str) {
        std::stringstream ss(str);
        double d1;
        ss >> d1;
        return new Circle(d1);
    }
    Circle(double radius): radius(radius){}
    virtual double get_square() const { return M_PI*radius*radius;}
    virtual ~Circle() {}
    virtual std::string to_string() const{return std::to_string(1.0);}
};
