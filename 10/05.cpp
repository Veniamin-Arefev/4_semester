//
// Created by Veniamin_Arefev on 15.05.2021.
//
#include <iostream>
#include <string>


int main() {
    bool was_only_S_left_rule = false;
    bool was_full_terminal_left_rule = false;

    bool only_one_not_terminal_left_rule = true;
    bool not_shortening_rules = true;

    //exception handle
    bool was_S_in_right_rule = false;
    bool was_epsilon_in_S_rule = false;

    std::string left_rule, right_rule;
    while (std::cin >> left_rule) {
        std::cin >> right_rule;

        //check left side
        if (left_rule.length() == 1u) {
            if (left_rule[0] == 'S') {
                was_only_S_left_rule = true;
            }
        } else {
            only_one_not_terminal_left_rule = false;
        }

        if (true) { // just for hiding was_not_terminal bool
            bool was_not_terminal = false;
            for (char sym : left_rule) {
                if (sym >= 'A' && sym <= 'Z') {
                    was_not_terminal = true;
                }
            }
            if (!was_not_terminal) {
                was_full_terminal_left_rule = true;
            }
        }

        //check right side
        if (left_rule.size() > right_rule.size()) {
            not_shortening_rules = false;
        }

        for (char sym : right_rule) {
            if (sym == 'S') {
                was_S_in_right_rule = true;
            }
        }

        if (right_rule.size() == 1u && right_rule[0] == '_') {
            if (left_rule.length() == 1u && left_rule[0] == 'S') {
                was_epsilon_in_S_rule = true;
            } else {
                not_shortening_rules = false; // epsilon in not "S -> epsilon" rule
            }
        }
    }

    if (was_full_terminal_left_rule || !was_only_S_left_rule) {
        std::cout << -1;
    } else if (only_one_not_terminal_left_rule) {
        if (not_shortening_rules && (!was_epsilon_in_S_rule || !was_S_in_right_rule)) {
            std::cout << 23;
        } else {
            std::cout << 2;
        }
    } else {
        std::cout << 10;
    }
}