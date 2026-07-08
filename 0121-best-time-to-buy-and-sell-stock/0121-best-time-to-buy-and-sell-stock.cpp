class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int buy = prices[0];
        for(int i = 0; i <n;i++){
            if(prices[i] < buy){
                buy = prices[i];
            }
            else if(prices[i] - buy > maxProfit){
                maxProfit = prices[i] - buy;
            }
        }
        return maxProfit;
    }
};