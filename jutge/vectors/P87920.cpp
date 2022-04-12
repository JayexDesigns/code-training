#include <iostream>
#include <vector>

using namespace std;

int main() {
    int times;
    while(cin >> times) {
        int sum = 0;
        vector<int> nums;
        for (int i = 0; i < times; ++i){
            int num;
            cin >> num;
            nums.push_back(num);
            sum += num;
        }

        bool equal = false;
        for (int i = 0; i < times; ++i) {
            if (nums[i] == sum - nums[i]) {
                equal = true;
                break;
            }
        }
        if (equal) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}