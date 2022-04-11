//A leap year has 366 days. After the Gregorian reform,
//the leap years are those multiple of four that do not end with two zeros,
//and also the years ending with two zeros such that, after removing these two zeros,
//are divisible by four. Thus, 1800 and 1900, although being multiples of four,
//were not leap years; by contrast, 2000 was a leap year.

#include <iostream>
#include <string>

using namespace std;

int main() {
    int inter0, inter1, inter2, inter3;
    cin >> inter0 >> inter1 >> inter2 >> inter3;
    int range0, range1;

    if (inter1 < inter2 || inter0 > inter3) {
        cout << "[" << "]" << endl;
    }
    else {
        if (inter0 <= inter2) range0 = inter2;
        else range0 = inter0;
        if (inter1 >= inter3) range1 = inter3;
        else range1 = inter1;
        cout << "[" << range0 << "," << range1 << "]" << endl;
    }

    return 0;
}