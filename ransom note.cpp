class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;
        for(auto c : magazine)
            freq[c]++;
        for(auto c : ransomNote)
            if(freq[c]) freq[c]--;
            else return false;
        return true;
    }
};
