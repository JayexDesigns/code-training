#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    int a, b;
    int topNum;
    cin >> a >> b;
    if (a > b) topNum = a;
    else if (b >= a) topNum = b;
    for (int i = 0; i <= abs(a-b); ++i) {
        cout << topNum - i << endl;
    }
}