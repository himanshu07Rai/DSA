class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int Min = prices[0];
        for(int i=1;i<n;i++)
        {
            if(prices[i]<Min)
            {
                Min = prices[i];
            }
            profit = max(profit,prices[i]-Min);               
            
        }
        return profit;
    }
};