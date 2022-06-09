#include <sstream>
#include "utils.hpp"

bool isDigit(char c)
{
    return '0' <= c and c <= '9';
}

bool isNumber(string s)
{
    if (int(s.size()) == 0) return false;
	for (int i = 0; i < int(s.size()); ++i)
        if (not isDigit(s[i]))
            return false;
    return true;
}

int mystoi(string s)
{
    istringstream mycin(s);
    int x;
    mycin >> x;
    return x;
}
