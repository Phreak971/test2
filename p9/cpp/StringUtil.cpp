#include "StringUtil.h"
#include <cstring>
std::string StringUtil::Concatenate(std::string a, std::string b)
{
    return a + b;
}

void StringUtil::Reverse(std::string &a)
{
    int length = a.length();
    for (int i = 0; i < length / 2; ++i)
    {
        // Swap characters at positions i and length - i - 1
        a[i] ^= a[length - i - 1];
        a[length - i - 1] ^= a[i];
        a[i] ^= a[length - i - 1];
    }
}

void StringUtil::Trim(std::string &a)
{
    // Remove leading whitespace
    size_t start = a.find_first_not_of(" \t\r\n");
    if (start != std::string::npos)
    {
        a = a.substr(start);
    }
    else
    {
        // If string contains only whitespace
        a.clear();
        return;
    }

    // Remove trailing whitespace
    size_t end = a.find_last_not_of(" \t\r\n");
    if (end != std::string::npos)
    {
        a = a.substr(0, end + 1);
    }
}
