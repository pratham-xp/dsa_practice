class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        if(nums.size() > 1)
        temp.push_back(nums[1]);
        for(int i = 2; i < nums.size(); i++)
            if(nums[i] != nums[i-1] || nums[i] != nums[i-2])
                temp.push_back(nums[i]);
        nums = temp;
        return nums.size();
    }
};
