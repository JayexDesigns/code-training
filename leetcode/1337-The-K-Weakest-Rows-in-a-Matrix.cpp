class Solution {
public:
    vector<int> sortRows(vector<int>& r, int k) {
        vector<int> res;
        while(!r.empty() && k != 0) {
            int min = -1;
            for (unsigned int i = 0; i < r.size(); ++i) {
                if (min == -1 && r[i] != -1) min = i;
                else if (min == -1) continue;
                if (r[i] < r[min] && r[i] != -1) min = i;
            }
            res.push_back(min);
            r[min] = -1;
            --k;
        }
        return res;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> rows(mat.size());
        for (unsigned int i = 0; i < mat.size(); ++i) {
            for (unsigned int j = 0; j < mat[i].size(); ++j) {
                if (mat[i][j] == 0) break;
                rows[i] += mat[i][j];
            }
        }
        return sortRows(rows, k);
    }
};