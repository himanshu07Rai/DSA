class Solution {
public:
    int solve(int i,int bye,vector<int>& prices,vector<vector<int>>&dp)
    {
        if(i==prices.size())
            return 0;
        if(dp[i][bye]!=-1)
            return dp[i][bye];
        if(bye)
        {
            return dp[i][bye] = max(-prices[i]+solve(i+1,0,prices,dp),solve(i+1,1,prices,dp));
        }else{
            return dp[i][bye] = max(prices[i]+solve(i+1,1,prices,dp),solve(i+1,0,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--)
        {
            dp[i][1]= max(-prices[i]+dp[i+1][0],dp[i+1][1]);
            dp[i][0] = max(prices[i]+dp[i+1][1],dp[i+1][0]);
        }
        return dp[0][1];
    }
};