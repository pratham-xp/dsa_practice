class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), res = 0;
        vector<int> freq(n+1, 0);
        
        for(auto x : citations){
            if(x >= n)
                freq[n]++;
            else freq[x]++;
        }

        for(int i = n; i >= 0; i--){
            res += freq[i];
            if(res >= i)
                return i;
        }
        return 0;
    }
};
