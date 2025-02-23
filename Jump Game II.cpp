class Solution {
public:
    int jump(vector<int>& nums) {
        int destination = nums.size() - 1, farthest = 0, minJumps = 0, lastJumpIdx = 0;
        if(nums.size() == 1) return 0;
        for(int i = 0; i < nums.size(); i++){
           farthest = max(farthest, i + nums[i]);
           if(i == lastJumpIdx){
            lastJumpIdx = farthest;
            minJumps++;
             if (farthest >= destination)
                return minJumps;
           }
        }
        return minJumps;
    }
};
