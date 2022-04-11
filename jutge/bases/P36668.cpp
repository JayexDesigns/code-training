#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
    int entry;
    cin >> entry;
    int a = 0;
    for (int i = 1; i <= entry; i++) {
        a += i*i;
    }
    cout << a << endl;
}