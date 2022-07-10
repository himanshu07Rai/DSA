class Solution {
public:
    int minCost(vector<int>& cost,int n,vector<int>& dp)
    {
        if(n<=1)
            return dp[n]=cost[n];
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=cost[n]+min(minCost(cost,n-1,dp),minCost(cost,n-2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        // int first = cost[0],second = cost[1];
        // for(int i=2;i<n;i++)
        // {
        //     int curr = cost[i]+min(first,second);
        //     first = second;
        //     second = curr;
        // }
        return min(minCost(cost,n-1,dp),minCost(cost,n-2,dp));
    }
};