class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string word1Res = "";
        string word2Res = "";
        for (int i = 0; i < word1.size(); ++i) {
            word1Res += word1[i];
        }
        for (int i = 0; i < word2.size(); ++i) {
            word2Res += word2[i];
        }
        return word1Res == word2Res;
    }
};