#include <iostream>
#include <climits> // For integer limits
#include <cfloat>  // For floating-point limits

int main()
{
    std::cout << "Size of Fundamental C++ Data Types:\n\n";

    // Character Types
    std::cout << "char:              " << sizeof(char) << " byte\n";
    std::cout << "signed char:       " << sizeof(signed char) << " byte\n";
    std::cout << "unsigned char:     " << sizeof(unsigned char) << " byte\n";
    std::cout << "wchar_t:           " << sizeof(wchar_t) << " bytes\n"; // Wide character
    // char16_t and char32_t are primarily for Unicode support
    std::cout << "char16_t:          " << sizeof(char16_t) << " bytes\n";
    std::cout << "char32_t:          " << sizeof(char32_t) << " bytes\n\n";

    // Integer Types
    std::cout << "short:             " << sizeof(short) << " bytes\n";
    std::cout << "int:               " << sizeof(int) << " bytes\n";
    std::cout << "long:              " << sizeof(long) << " bytes\n";
    std::cout << "long long:         " << sizeof(long long) << " bytes\n";
    std::cout << "unsigned short:    " << sizeof(unsigned short) << " bytes\n";
    std::cout << "unsigned int:      " << sizeof(unsigned int) << " bytes\n";
    std::cout << "unsigned long:     " << sizeof(unsigned long) << " bytes\n";
    std::cout << "unsigned long long:" << sizeof(unsigned long long) << " bytes\n\n";

    // Floating-Point Types
    std::cout << "float:             " << sizeof(float) << " bytes\n";
    std::cout << "double:            " << sizeof(double) << " bytes\n";
    std::cout << "long double:       " << sizeof(long double) << " bytes\n\n";

    // Boolean Type
    std::cout << "bool:              " << sizeof(bool) << " byte\n\n";

    // void Type (Technically not a data type, but useful to know)
    std::cout << "void:              " << sizeof(void *) << " bytes (size of a pointer)\n\n";

    return 0;
}
