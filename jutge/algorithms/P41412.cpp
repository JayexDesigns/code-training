#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<double>& v) {
    for (int i = 1; i < (int)v.size(); ++i) {
        int j = i;
        while (j > 0 && v[j-1] > v[j]) {
            double tmp = v[j];
            v[j] = v[j-1];
            v[j-1] = tmp;
            j--;
        }
    }
}

void print_vector(vector<double> v) {
    for (int i = 0; i < (int)v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<double> test = {2, 1, 6, 5, 3, 4};
    insertion_sort(test);
    print_vector(test);
    return 0;
}