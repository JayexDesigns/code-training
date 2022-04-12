#include <iostream>
#include <vector>

using namespace std;

int first_occurrence(double x, const vector<double>& v) {
    int left = 0;
    int right = (int)v.size()-1;
    while (left <= right) {
        int pos = (left + right)/2;
        if (v[pos] == x && v[pos-1] != x) return pos;
        else if (v[pos] < x) left = pos+1;
        else right = pos-1;
    }
    return -1;
}
