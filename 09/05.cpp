//
// Created by Veniamin_Arefev on 19.04.2021.
//
#include "boost/date_time/gregorian/gregorian.hpp"
#include <iostream>
#include <string>

using namespace boost::gregorian;

int main(int argc, char **argv) {
    unsigned short year, month, day;
    char separator;
    unsigned long long sum = 0;

    std::cin >> year >> separator >> month >> separator >> day;
    date last_date(year,month,day);
    while (std::cin >> year >> separator >> month >> separator >> day) {
        date new_date(year,month,day);
        sum += std::abs((new_date - last_date).days());
        last_date = new_date;
    }
    std::cout << sum << std::endl;
}