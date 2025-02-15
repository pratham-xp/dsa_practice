class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int profit = 0, minEle = prices[0];
       for(int i = 0; i < prices.size(); i++){
        minEle = min(minEle, prices[i]);
        if(prices[i] > minEle){
            profit += prices[i] - minEle;
            minEle = prices[i];
        }
       }
       return profit; 
    }
};
