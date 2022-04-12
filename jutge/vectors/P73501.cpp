#include <iostream>
#include <string>
#include <vector>

using namespace std;

int increasingPairs(vector<int> nums) {
    int pairs = 0;
    for (int i = 0; i < (int)nums.size()-1; ++i) {
        if (nums[i] < nums[i+1]) pairs++;
    }
    return pairs;
}

int main() {
    int quantity;
    cin >> quantity;
    for (int i = 0; i < quantity; ++i) {
        int num;
        vector<int> nums;
        do {
            cin >> num;
            nums.push_back(num);
        } while (num != 0);
        cout << increasingPairs(nums) << endl;
    }

    return 0;
}