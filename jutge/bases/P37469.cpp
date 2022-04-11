#include <iostream>

using namespace std;

int main() {
    int hours, min, sec;
    int entry;
    cin >> entry;

    sec = entry % 60;
    min = (int)(entry - entry % 60)/60;
    hours = (int)(min - min % 60)/60;
    min = min % 60;

    cout << hours << " " << min << " " << sec << endl;
    return 0;
}