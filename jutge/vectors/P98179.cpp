#include <iostream>
#include <vector>

using namespace std;

void insert(vector<double>& v) {
    if (v[(int)v.size()-2] > v[(int)v.size()-1]) {
        double valueToSort = v[(int)v.size()-1];
        v[(int)v.size()-1] = v[(int)v.size()-2];
        for (int i = 0; i < (int)v.size(); ++i) {
            if (v[i] > valueToSort) {
                double tmp = v[i];
                v[i] = valueToSort;
                valueToSort = tmp;
            }
        }
    }
}

int main() {
    return 0;
}