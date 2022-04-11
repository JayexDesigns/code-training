#include <iostream>

using namespace std;

int main() {
    char vol;
    cin >> vol;
    double n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    if (vol == 'C') cout << n1 * n2 * n3 << endl;
    else if (vol == 'R') cout << (n1 * n2 * n3)/3 << endl;
    else if (vol == 'P') cout << ((n1 * 5) * n3)/2 * n2 << endl;
    return 0;
}