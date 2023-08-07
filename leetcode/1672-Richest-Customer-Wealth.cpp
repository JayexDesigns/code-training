class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        for (unsigned int i = 0; i < accounts.size(); ++i) {
            int current = 0;
            for (unsigned int j = 0; j < accounts[i].size(); ++j) current += accounts[i][j];
            if (current > max) max = current;
        }
        return max;
    }
};