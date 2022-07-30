class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int Min = prices[0];
        for(int i=1;i<n;i++)
        {
            int cost = prices[i]-Min;
            profit = max(profit,cost);
            Min = min(Min,prices[i]);               
            
        }
        return profit;
    }
};