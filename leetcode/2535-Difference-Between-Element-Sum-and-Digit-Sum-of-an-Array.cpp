class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = 0;
        int digitSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            elementSum += num;
            while (num > 0) {
                digitSum += num % 10;
                num /= 10;
            }
        }
        int difference = elementSum - digitSum;
        return (difference > 0) ? difference : -difference;
    }
};