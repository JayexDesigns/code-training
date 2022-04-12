#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n1;
    while (cin >> n1) {
        vector<int> v1;
        for (int i = 0; i < n1; ++i) {
            int value;
            cin >> value;
            v1.push_back(value);
        }
        int n2;
        cin >> n2;
        vector<int> v2;
        for (int i = 0; i < n2; ++i) {
            int value;
            cin >> value;
            v2.push_back(value);
        }

        int i1 = 0;
        int i2 = 0;
        int maxVal = 0;
        int maxNum = 0;
        int currVal = 0;
        int currNum = 0;
        while (i1 < int(v1.size()) || i2 < int(v2.size())) {
            if (
                (i2 >= int(v2.size()) && i1 < int(v1.size())) ||
                (i1 < int(v1.size()) && i2 < int(v2.size()) &&
                v1[i1] < v2[i2])
            ) {
                if (v1[i1] != currVal) {
                    currVal = v1[i1];
                    currNum = 0;
                }
                ++currNum;
                ++i1;
            }

            else if (
                (i1 >= int(v1.size()) && i2 < int(v2.size())) ||
                (i1 < int(v1.size()) && i2 < int(v2.size()) &&
                v2[i2] < v1[i1])
            ) {
                if (v2[i2] != currVal) {
                    currVal = v2[i2];
                    currNum = 0;
                }
                ++currNum;
                ++i2;
            }

            else if (v1[i1] == v2[i2]) {
                if (v1[i1] != currVal) {
                    currVal = v1[i1];
                    currNum = 0;
                }
                currNum += 2;
                ++i1;
                ++i2;
            }

            if (currNum >= maxNum) {
                maxVal = currVal;
                maxNum = currNum;
            }
        }
        cout << maxVal << " " << maxNum << endl;
    }
    return 0;
}