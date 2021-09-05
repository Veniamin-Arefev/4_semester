//
// Created by Veniamin_Arefev on 15.05.2021.
//
#include <iostream>

/*
 Grammar:
S -> aAd
A -> aAd | bBc
B -> bBc | eps
*/

void B(int inner_pairs) {
    if (inner_pairs > 1) {
        std::cout << 'b';
        B(inner_pairs - 1);
        std::cout << 'c';
    }
}

void A(int k, int inner_pairs) {
    if (k / 2 - inner_pairs > 0) {
        std::cout << 'a';
        A(k - 2, inner_pairs);
        std::cout << 'd';
    } else {
        std::cout << 'b';
        B(inner_pairs);
        std::cout << 'c';
    }
}

void S(int k, int inner_pairs) {
    std::cout << 'a';
    A(k - 2, inner_pairs);
    std::cout << 'd';
}

void main_recursion(int k, int outer_pairs) {
    if (outer_pairs > 0) {
        S(k, k / 2 - outer_pairs);
        std::cout << std::endl;
        main_recursion(k, outer_pairs - 1);
    }
}


int main() {
    int k;
    std::cin >> k;
    if ((k & 1) == 0 && k >= 4) {
        main_recursion(k, k / 2 - 1);
    }
}
