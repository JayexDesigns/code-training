class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (j != i && nums[j] < nums[i]) ++sum;
            }
            res[i] = sum;
        }
        return res;
    }
};