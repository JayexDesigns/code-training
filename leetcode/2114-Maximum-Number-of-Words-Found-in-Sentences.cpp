class Solution {
public:
    int countWords(string sentence) {
        int words = sentence.size() == 0 ? 0 : 1;
        for (int i = 0; i < sentence.size(); ++i) {
            if (sentence[i] == ' ') ++words;
        }
        return words;
    }

    int mostWordsFound(vector<string>& sentences) {
        int max = 0;
        for (int i = 0; i < sentences.size(); ++i) {
            int res = countWords(sentences[i]);
            if (res > max) max = res;
        }
        return max;
    }
};