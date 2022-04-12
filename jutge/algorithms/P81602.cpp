#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<double> v) {
    for (int i = 0; i < (int)v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void selection_sort(vector<double>& v, int m) {
    if (m <= 0) return;
    int maxIndex = m;
    for (int index = m - 1; index >= 0; --index) {
        if (v[index] > v[maxIndex]) maxIndex = index;
    }
    double temp = v[m];
    v[m] = v[maxIndex];
    v[maxIndex] = temp;
    selection_sort(v, --m);
}

int main() {
    vector<double> test = {2, 1, 6, 5, 3, 4};
    selection_sort(test, 3);
    print_vector(test);
    return 0;
}