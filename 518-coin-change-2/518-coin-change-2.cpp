class Solution {
public:
    int solve(int i,int remainingAmount,vector<int>& coins,vector<vector<int>>&dp)
    {
        if(i==0)
        {
            return (remainingAmount%coins[i]==0);
        }
        if(dp[i][remainingAmount]!=-1)
            return dp[i][remainingAmount];
        int notTake = solve(i-1,remainingAmount,coins,dp);
        int take = 0;
        if(coins[i]<=remainingAmount)
        {
            take = solve(i,remainingAmount-coins[i],coins,dp);
        }
        return dp[i][remainingAmount] = take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};