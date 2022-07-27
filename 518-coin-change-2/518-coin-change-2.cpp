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
        vector<int>prev(amount+1,0);
        for(int j=0;j<=amount;j++)
        {
            prev[j] = (j%coins[0]==0);
        }
        for(int i=1;i<n;i++)
        {
            for(int remainingAmount = 0;remainingAmount<=amount;remainingAmount++)
            {
                int notTake = prev[remainingAmount];
                int take = 0;
                if(coins[i]<=remainingAmount)
                {
                    take = prev[remainingAmount-coins[i]];
                }
                prev[remainingAmount] = take+notTake;
            }
        }
        return prev[amount];
    }
};