#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double num;
    cin >> num;
    int numFloor = floor(num);
    int numCeil = ceil(num);
    int numRound = round(num);

    cout << numFloor << " " << numCeil << " " << numRound << endl;
    return 0;
}