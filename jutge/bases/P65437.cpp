#include <iostream>
#include <string>

using namespace std;

void swap2(int& a, int& b) {
    a = b + a;
    b = a - b;
    a = a - b;
}

int main() {
    return 0;
}