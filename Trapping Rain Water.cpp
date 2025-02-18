class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = 0, low = 0, high = height.size()-1, ans = 0;
        while(low < high){
            left = max(left,height[low]);
            right = max(right, height[high]);
            if(left < right){
                ans += left-height[low];
                low++;
            } else{
                ans += right-height[high];
                high--;
            }
        }
        return ans;
    }
};
