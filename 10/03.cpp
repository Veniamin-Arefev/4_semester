//
// Created by Veniamin_Arefev on 26.04.2021.
//
#include <string>
#include <iostream>

// a^(n)0^(m)b^(n)1^(m) , n>0m>0

int main() {
    std::string in;
    int type;
    bool belongs;
    int n_count;
    int m_count;
    while (std::cin >> in) {
        belongs = true;
        type = 0;
        n_count = 0;
        m_count = 0;
        for (char i : in) {
            if (i == 'a') {
                if (type != 0 && type != 1) {
                    belongs = false;
                    break;
                }
                ++n_count;
                type = 1;
            } else if (i == '0') {
                if (type != 1 && type != 2) {
                    belongs = false;
                    break;
                }
                ++m_count;
                type = 2;
            } else if (i == 'b') {
                if (type != 2 && type != 3) {
                    belongs = false;
                    break;
                }
                --n_count;
                type = 3;
            } else if (i == '1') {
                if (type != 3 && type != 4) {
                    belongs = false;
                    break;
                }
                --m_count;
                type = 4;
            }
        }
        if (type != 4) {
            belongs = false;
        }
        if (n_count != 0 || m_count != 0) {
            belongs = false;
        }
        std::cout << belongs << std::endl;
    }
}