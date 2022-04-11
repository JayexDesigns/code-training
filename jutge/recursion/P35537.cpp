#include <iostream>

using namespace std;

bool is_increasing(int n) {
    if (n < 10) return true;
    if (n%10 < (int(n/10))%10) return false;
    return is_increasing(int(n/10));
}

int main() {
    int num;
    cin >> num;
    cout << is_increasing(num) << endl;
    return 0;
}