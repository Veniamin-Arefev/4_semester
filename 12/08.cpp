//
// Created by Veniamin_Arefev on 17.05.2021.
//

#include <string>
#include <cinttypes>

std::string gen_power(uint32_t power) {

    if (power == 0) {
        return std::string("1");
    } else if (power == 1){
        return std::string("x");
    } else {
        return std::string(power,'x')+std::string(power-1,'*');
    }
}

