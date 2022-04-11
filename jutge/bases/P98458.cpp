#include <string>

using namespace std;

void min_max(int a, int b, int& mn, int& mx) {
    if (a < b) {
        mn = a;
        mx = b;
    }
    else {
        mn = b;
        mx = a;
    }
}

int main() {
    return 0;
}