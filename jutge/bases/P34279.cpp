#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int hour, min, sec;
    cin >> hour >> min >> sec;

    sec++;
    if (sec == 60) {
        min++;
        sec = 0;
    };
    if (min == 60) {
        hour++;
        min = 0;
    };
    if (hour == 24) hour = 0;

    printf("%02d:%02d:%02d\n", hour, min, sec);
    return 0;
}