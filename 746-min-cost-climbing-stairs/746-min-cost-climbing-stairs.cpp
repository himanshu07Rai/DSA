class Solution {
public:
    // int minCost(vector<int>& cost,int n,vector<int>& dp)
    // {
    //     if(n<=1)
    //         return dp[n] = cost[n];
    //     if(dp[n])
    //         return dp[n];
    //     return dp[n] = cost[n]+min(minCost(cost,n-1,dp),minCost(cost,n-2,dp));
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,0);
        for(int i=0;i<n;i++)
        {
            if(i<2)dp[i] = cost[i];
            else dp[i] = cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};