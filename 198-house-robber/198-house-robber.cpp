class Solution {
public:
    int solve(int n,vector<int>& nums,vector<int>& dp)
    {
        if(n==0)
            return 0;
        if(n==1)
            return nums[n-1];
        if(dp[n]!=-1)
            return dp[n];
        int pick = nums[n-1]+solve(n-2,nums,dp);
        int notPick = solve(n-1,nums,dp);
        return dp[n]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();  
        vector<int>dp(n+1,-1);
        return solve(n,nums,dp);
    }
};