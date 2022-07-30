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
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};