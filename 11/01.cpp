//
// Created by Veniamin_Arefev on 16.05.2021.
//
#include <iostream>
#include <string>


int main() {
    //exception handle
    bool was_S_in_right_rule = false;
    bool was_epsilon_in_S_rule = false;
    bool not_shortening_rules = true;

    bool was_one_not_term = false;

    bool is_regular = true;
    bool is_right_gram = false;
    bool is_left_gram = false;
    bool is_auto_gram = true;

    std::string left_rule, right_rule;
    while (std::cin >> left_rule) {
        std::cin >> right_rule;

        //check right side
        int terms = 0;
        int not_terms = 0;
        for (char sym : right_rule) {
            if (isupper(sym)) { // A - Z
                ++not_terms;
            } else {
                ++terms;
            }
            if (sym == 'S') {
                was_S_in_right_rule = true;
            }
        }

        if (right_rule.size() == 1u && right_rule[0] == '_') {
            if (left_rule[0] == 'S') {
                was_epsilon_in_S_rule = true;
            } else {
                not_shortening_rules = false; // epsilon in not "S -> epsilon" rule
                is_auto_gram = false;
            }
        } else if (terms == 0 && not_terms == 1 && !was_one_not_term) {
            was_one_not_term = true;
        } else if (terms != 1) {
            is_auto_gram = false;
        }

        // about N or {T} we cant say anything and then we skip them
        if (!((not_terms == 1 && terms == 0) || not_terms == 0)) {
            if (not_terms == 1) {
                if (isupper(right_rule[0]) && !is_right_gram) { //N{T}
                    is_left_gram = true;
                } else if (isupper(right_rule[right_rule.size() - 1]) && !is_left_gram) { // {T}N
                    is_right_gram = true;
                } else {
                    is_regular = false;
                }
            } else {
                is_regular = false;  // is not one of N N{T} {T}N
            }
        }
    }

    if (was_one_not_term && was_S_in_right_rule) { //if was_one_not_term == true => was_S_in_right_rule must be false
        is_auto_gram = false;
    }

    //if is right and left it becomes not regular
    if (is_regular) {
        std::cout << (is_auto_gram ? (is_right_gram ? 321 : 311) : (is_right_gram ? 32 : 31)) << std::endl;
    } else {
        std::cout << (not_shortening_rules && (!was_epsilon_in_S_rule || !was_S_in_right_rule) ? 21 : 2) << std::endl;
    }
}