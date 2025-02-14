class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> freq;
        for(auto x : nums)
            freq[x]++;
        for(auto x : nums){
            if(k-x > 0 && freq[k-x]>0 && freq[x]>0 && (x!=k/2 || freq[x]!=1)){
                freq[x]--;
                freq[k-x]--;
                count++;
            }
        }
        return count;
    }
};
