#include <iostream>
#include <vector>

using namespace std;

int position_maximum(const vector<double>& v, int m) {
    int max;
    for (int i = 0; i <= m; ++i) {
        if (i == 0) max = i;
        else {
            if (v[i] > v[max]) max = i;
        }
    }
    return max;
}

int main() {
    int m, n;
    while (cin >> m >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        cout << position_maximum(V, m) << endl;
    }
}