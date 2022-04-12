#include <iostream>
#include <vector>

using namespace std;

int position(double x, const vector<double>& v, int left, int right) {
    if ((left > right) || (left == right && v[left] != x)) return -1;
    int pos = int((left + right)/2);
    if (v[pos] == x) return pos;
    else if (x < v[pos]) right = pos-1;
    else if (x > v[pos]) left = pos+1;
    return position(x, v, left, right);
}

int main() {
    return 0;
}