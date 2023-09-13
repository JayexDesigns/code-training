class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> answer(nums.size(), 0);
        vector<int> left(nums.size(), 0);
        vector<int> right(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                left[i] += nums[j];
                right[nums.size() - i - 1] += nums[nums.size() - j - 1];
            }
        }
        for (int i = 0; i < answer.size(); ++i) {
            answer[i] = left[i] - right[i];
            if (answer[i] < 0) answer[i] *= -1;
        }
        return answer;
    }
};