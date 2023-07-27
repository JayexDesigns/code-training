class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        for (int i = 1; i <= arr.size(); i += 2) {
            for (int j = 0; (j + i - 1) < arr.size(); ++j) {
                for (int k = j; k < j + i; ++k) {
                    sum += arr[k];
                }
            }
        }
        return sum;
    }
};