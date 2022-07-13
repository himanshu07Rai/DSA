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
        vector<int>dp(n+1,0);
        dp[1] = nums[0];
        for(int i=2;i<=n;i++)
        {
            int pick = nums[i-1];
            if(i>1)
            {
                pick+=dp[i-2];
            }
            int notPick = dp[i-1];
            dp[i] = max(pick,notPick);
        }
        return dp[n];
    }
};