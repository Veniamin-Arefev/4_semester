//
// Created by Veniamin_Arefev on 20.02.2021.
//
#include <iostream>
#include <string>

using namespace std;

class BinaryNumber {
    string number_string;
public:
    BinaryNumber(const string &s) {
        number_string = s;
    }

    operator std::string() const {
        return number_string;
    }

    const BinaryNumber &operator++() {
        int len = number_string.length();
        number_string = '0' + number_string;
        for (int i = len; i >= 0; i--) {
            if (number_string[i] == '0') {
                number_string[i] = '1';
                break;
            } else {
                number_string[i] = '0';
            }
        }
        if (number_string[0] == '0') {
            number_string = number_string.substr(1, len);
        }
        return *this;
    }
};

int main() {
    BinaryNumber num = BinaryNumber("101");
}


