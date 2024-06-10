#include <iostream>
#include <bitset>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>
std::string bitsetToString(const std::bitset<128>& bs) {
    std::string result;
    for (int i = bs.size() - 1; i >= 0; --i) {
        result += bs[i] ? '1' : '0';
    }
    return result;
}

int main() {
    std::bitset<128> int128 = 170141183460469231731687303715884105727;
    
    std::cout << "Binary: " << bitsetToString(int128) << std::endl;
    std::cout << "Decimal: 170141183460469231731687303715884105727" << std::endl; // Manual entry due to size constraints
    
    return 0;
}
