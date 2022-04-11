#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int c, d;
    c = floor(a/double(b));
    d = a - (c * b);
    cout << c << " " << d << endl;
    return 0;
}