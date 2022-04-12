#include "LlistaIOParInt.hh"

int main() {
    list<ParInt> l;
    cin >> l;

    int n;
    cin >> n;

    int quantity = 0;
    int sum = 0;
    while (!l.empty()) {
        if (l.front().primer() == n) {
            ++quantity;
            sum += l.front().segon();
        }
        l.pop_front();
    }

    cout << n << ' ' << quantity << ' ' << sum << endl;

    return 0;
}