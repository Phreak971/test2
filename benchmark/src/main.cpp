#include <iostream>
#include <limits>
#include "Instrumentor.h"


int main()
{
    std::cout << std::numeric_limits<long>::min() << std::endl;
    std::cout << std::numeric_limits<long long>::min() << std::endl;
    std::cout << std::numeric_limits<long int>::min() << std::endl;
    std::cout << std::numeric_limits<long long int>::min() << std::endl;
}