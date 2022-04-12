#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<double>& v) {
    for (int i = 1; i < (int)v.size(); ++i) {
        for (int j = 0; j < (int)v.size()-1; ++j) {
            if (v[j] > v[j+1]) {
                double tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }
}

int main() {
    return 0;
}