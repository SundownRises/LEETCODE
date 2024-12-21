class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
    int hold = -prices[0];
    int sell = 0;        
    for (int i = 1; i < prices.size(); i++) {
        hold = max(hold, sell - prices[i]);
        sell = max(sell, hold + prices[i] - fee);
    }
    
    return sell;
    }
};