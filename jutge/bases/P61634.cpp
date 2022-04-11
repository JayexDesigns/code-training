//A leap year has 366 days. After the Gregorian reform,
//the leap years are those multiple of four that do not end with two zeros,
//and also the years ending with two zeros such that, after removing these two zeros,
//are divisible by four. Thus, 1800 and 1900, although being multiples of four,
//were not leap years; by contrast, 2000 was a leap year.

#include <iostream>
#include <string>

using namespace std;

int main() {
    int year;
    cin >> year;
    string out;

    if (year == 2000) out = "YES";
    else if (year == 1800 || year == 1900) out = "NO";
    else if (year % 4 == 0) {
        if (to_string(year).substr(2, 2) != "00") {
            out = "YES";
        }
        else {
            if (std::stoi(to_string(year).substr(0, 2)) % 4 == 0) out = "YES";
            else out = "NO";
        }
    }
    else out = "NO";

    cout << out << endl;
    return 0;
}