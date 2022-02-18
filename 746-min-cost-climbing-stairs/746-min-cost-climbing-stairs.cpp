class Solution {
public:
    int minCost(vector<int>& cost,int n,vector<int>& dp)
    {
        if(n<=1)
            return dp[n] = cost[n];
        if(dp[n])
            return dp[n];
        return dp[n] = cost[n]+min(minCost(cost,n-1,dp),minCost(cost,n-2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,0);
        return min(minCost(cost,n-1,dp),minCost(cost,n-2,dp));
    }
};