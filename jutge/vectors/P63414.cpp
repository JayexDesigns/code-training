#include <iostream>
#include <vector>

using namespace std;

int main () {
    int minNum = 1000000000;
    int endDiff = 1001;
    vector<int> nums(endDiff, 0);
    int quantity;
    cin >> quantity;

    for (int i = 0; i < quantity; ++i) {
        int x;
        cin >> x;
        ++nums[x - minNum];
    }
    for (int i = 0; i < endDiff; ++i) {
        if (nums[i] != 0) cout << minNum + i << " : " << nums[i] << endl;
    }
}