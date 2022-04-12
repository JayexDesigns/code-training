#include <iostream>
#include <vector>

using namespace std;

int mitjana_menor(const vector<int> &v, int k) {
    int min;
    int index = 0;
    int sum = 0;
    for (int i = 0; i <= (int)v.size() - k; ++i) {
        if (i == 0) {
            for (int j = 0; j < k; ++j) sum += v[i + j];
            min = sum;
        }
        else {
            sum -= v[i - 1];
            sum += v[i - 1 + k];
            if (sum < min) {
                min = sum;
                index = i;
            }
        }
    }

    return index;
}

int main() {
    int s;
    cin >> s;
    int n;
    vector<int> v(s);
    cout << '[';
    for (int i = 0; i < s; ++i) {
        cin >> n;
        v[i] = n;
        if (i != 0) cout << ',';
        cout << n;
    }
    cout << ']' << endl;

    while (cin >> n) cout << mitjana_menor(v, n) << endl;

    return 0;
}