#include <iostream>

int main()
{
    int32_t num32 = -1;
    int64_t num64 = num32;

    std::cout << "num32: " << num32 << ", num64: " << num64 << std::endl;

    int64_t numx = 0xFFFFFFFF;
    uint32_t uNum32 = 0xFFFFFFFF;
    int64_t sNum64 = uNum32;
    std::cout << "uNum32: " << uNum32 << ", sNum64: " << sNum64 << std::endl;
}