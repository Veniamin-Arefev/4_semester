//
// Created by Veniamin_Arefev on 15.05.2021.
//

#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <algorithm>

int
main()
{
    std::map<char, std::vector<std::string>> gram_rules;
    std::string input_string;
    char input_char;
    while (std::cin >> input_char) {
        if (input_char == '+') {
            break;
        }
        std::cin >> input_string;
        gram_rules[input_char].push_back(input_string);
    }

    std::map<char, std::set<char>> gram_only_not_term;
    for (auto &rule :gram_rules) {
        for (auto &right_rule_str :rule.second) {
            for (char char_in_rule:right_rule_str) {
                if (isupper(char_in_rule)) {
                    gram_only_not_term[rule.first].insert(char_in_rule);
                }
            }
        }
    }
    std::set<char> achievable_not_terms;
    achievable_not_terms.insert('S');
    bool added_new_term;
    do {
        added_new_term = false;
        for (char left_char : achievable_not_terms) {
            for (char right_char:gram_only_not_term[left_char]) {
                if (achievable_not_terms.count(right_char) == 0) {
                    achievable_not_terms.insert(right_char);
                    added_new_term = true;
                }
            }
        }
    } while (added_new_term);

    for (auto &not_term: achievable_not_terms) {
        for (auto &right_rule :gram_rules[not_term]) {
            std::cout << not_term << " " << right_rule<<std::endl;
        }
    }
}
