#include <iostream>
#include <vector>

using namespace std;

vector<int> concatenation(const vector<int>& v1, const vector<int>& v2) {
    vector<int> out = {};
    for (int i = 0; i < (int)v1.size(); ++i) out.push_back(v1[i]);
    for (int i = 0; i < (int)v2.size(); ++i) out.push_back(v2[i]);
    return out;
}

int main() {
    return 0;
}