class Solution {
private:
    private:
    vector<string> helper(const string& s, int start, const unordered_set<string>& dict, int max_len, unordered_map<int, vector<string>>& memo) {
        if (start == s.length()) {
            return {""};
        }
        if (memo.find(start) != memo.end()) {
            return memo[start];
        }
        vector<string> result;
        for (int end = start + 1; end <= s.length() && end - start <= max_len; ++end) {
            string word = s.substr(start, end - start);
            if (dict.find(word) != dict.end()) {
                vector<string> sub_sentences = helper(s, end, dict, max_len, memo);
                for (const string& sub : sub_sentences) {
                    if (sub.empty()) {
                        result.push_back(word);
                    } else {
                        result.push_back(word + " " + sub);
                    }
                }
            }
        }
        memo[start] = result;
        return result;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int max_len = 0;
        for (const string& word : wordDict) {
            max_len = max(max_len, static_cast<int>(word.length()));
        }
        unordered_map<int, vector<string>> memo;
        return helper(s, 0, dict, max_len, memo);
    }
};
