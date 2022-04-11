//A leap year has 366 days. After the Gregorian reform,
//the leap years are those multiple of four that do not end with two zeros,
//and also the years ending with two zeros such that, after removing these two zeros,
//are divisible by four. Thus, 1800 and 1900, although being multiples of four,
//were not leap years; by contrast, 2000 was a leap year.

#include <iostream>
#include <string>

using namespace std;

int main() {
    return 0;
}

int absolute(int num) {
    if (num < 0) {
        return num * -1;
    }
    return num;
}