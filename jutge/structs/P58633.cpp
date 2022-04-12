#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Racional {
    int num, den;
};

Racional minim(const Racional& a, const Racional& b) {
    if (a.den * b.num >= a.num * b.den) return a;
    else return b;
}

Racional stringToRacional(string str) {
    string part1 = str.substr(0, str.find("/"));
    string part2 = str.substr(str.find("/")+1, (int)str.size()-1);
    Racional rac;
    rac.num = stoi(part1);
    rac.den = stoi(part2);
    return rac;
}

int main() {
    int n;
    cin >> n;
    vector<Racional> a = {};
    vector<Racional> b = {};
    for (int i = 0; i < n*2; ++i) {
        string num;
        cin >> num;
        if (i < n) a.push_back(stringToRacional(num));
        else b.push_back(stringToRacional(num));
    }
    for (int i = 0; i < n; ++i) {
        Racional res = minim(a[i], b[i]);
        cout << res.num << "/" << res.den << endl;
    }
    return 0;
}