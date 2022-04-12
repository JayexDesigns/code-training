#include <vector>

using namespace std;

bool exists(int x, const vector<int>& v) {
    for (int i = 0; i < (int)v.size(); ++i) {
        if (v[i] == x) {
            return true;
        }
    }
    return false;
}

int main() {
    return 0;
}