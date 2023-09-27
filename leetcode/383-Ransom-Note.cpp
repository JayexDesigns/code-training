class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> letters(26);
        for (unsigned int i = 0; i < magazine.size(); ++i)
            ++letters[magazine[i] - 'a'];

        for (unsigned int i = 0; i < ransomNote.size(); ++i) {
            if (letters[ransomNote[i] - 'a'] == 0) return false;
            --letters[ransomNote[i] - 'a'];
        }
        return true;
    }
};