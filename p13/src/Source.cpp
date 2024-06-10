#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    cout << "Let's check out these data type sizes, Snoop D-O-double-G style:\n\n";

    cout << "sizeof(char): " << sizeof(char) << " byte(s)\n";
    cout << "sizeof(signed char): " << sizeof(signed char) << " byte(s)\n";
    cout << "sizeof(unsigned char): " << sizeof(unsigned char) << " byte(s)\n";
    cout << "sizeof(short): " << sizeof(short) << " byte(s)\n";
    cout << "sizeof(unsigned short): " << sizeof(unsigned short) << " byte(s)\n";
    cout << "sizeof(int): " << sizeof(int) << " byte(s)\n";
    cout << "sizeof(unsigned int): " << sizeof(unsigned int) << " byte(s)\n";
    cout << "sizeof(long): " << sizeof(long) << " byte(s)\n";
    cout << "sizeof(unsigned long): " << sizeof(unsigned long) << " byte(s)\n";
    cout << "sizeof(long long): " << sizeof(long long) << " byte(s)\n";
    cout << "sizeof(unsigned long long): " << sizeof(unsigned long long) << " byte(s)\n";
    cout << "sizeof(float): " << sizeof(float) << " byte(s)\n";
    cout << "sizeof(double): " << sizeof(double) << " byte(s)\n";
    cout << "sizeof(long double): " << sizeof(long double) << " byte(s)\n";

    cout << "\nAnd for those fixed-width types you gotta include <cstdint>:\n\n";

    cout << "sizeof(int8_t): " << sizeof(int8_t) << " byte(s)\n";
    cout << "sizeof(uint8_t): " << sizeof(uint8_t) << " byte(s)\n";
    cout << "sizeof(int16_t): " << sizeof(int16_t) << " byte(s)\n";
    cout << "sizeof(uint16_t): " << sizeof(uint16_t) << " byte(s)\n";
    cout << "sizeof(int32_t): " << sizeof(int32_t) << " byte(s)\n";
    cout << "sizeof(uint32_t): " << sizeof(uint32_t) << " byte(s)\n";
    cout << "sizeof(int64_t): " << sizeof(int64_t) << " byte(s)\n";
    cout << "sizeof(uint64_t): " << sizeof(uint64_t) << " byte(s)\n";

    cout << "\nWord up! Now you know those sizes like a true G.\n";

    return 0;
}
