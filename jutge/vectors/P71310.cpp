#include <iostream>
#include <vector>

using namespace std;

double scalar_product(const vector<double>& u, const vector<double>& v) {
    double product = 0.0;
    for (int i = 0; i < (int)u.size(); ++i) {
        product += u[i] * v[i];
    }
    return product;
}

int main() {
    vector<double> u = {3, 4, -1};
    vector<double> v = {1, -2, 5};
    cout << scalar_product(u, v);
    return 0;
}