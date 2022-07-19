class Solution {
public:
    int solve(int n,vector<int>& nums,vector<int>&dp)
    {
        if(dp[n]!=-1)
            return dp[n];
        if(n==0)
            return dp[n] = nums[0];
        
        int append = solve(n-1,nums,dp)+nums[n];
        int New = nums[n];
        return dp[n]= max(append,New);
        
    }
    int maxSubArray(vector<int>& nums) {
        int maxSum = -1e7;
        int n = nums.size();
        int sum = nums[0];
        vector<int>dp(n,-1);
        int ans = solve(n-1,nums,dp);
        // for(int i:dp)
        //     cout<<i<<" ";
        // dp[0] = -1e7;
        return *max_element(dp.begin(),dp.end());
    }
};