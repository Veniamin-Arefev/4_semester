//
// Created by Veniamin_Arefev on 19.04.2021.
//
#include <string>
#include <iostream>

class S {
    std::string str;
public:
    ~S() {
        if (str.size() != 0) {
            std::cout << str << std::endl;
        }
    }

    S(std::string str) : str(str) {

    }
};

void recursion() {
    std::string str;
    while (std::cin >> str) {
        try {
            recursion();
        }
        catch (S &s) {
            throw S(str);
        }
    }
    throw S(std::string());
}

int main() {

    try {
        recursion();
    }
    catch (S &s) {
    }
}
