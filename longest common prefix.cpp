class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int i = 0;
        if(strs.size() == 1) return strs[0];
        while(i < strs[0].size()){
            int freq = 1;
            for(int j = 1; j < strs.size(); j++){
                if(strs[0][i] == strs[j][i])
                    freq++;
            }
            if(freq == strs.size())
                res += strs[0][i];
            else break;
            i++;
        }
        return res;
    }
};
