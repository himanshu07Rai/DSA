class Solution {
public:
    int solve(int n,vector<int>& nums,vector<int>&dp)
    {
        if(n==0)
            return -1e7;
        if(dp[n]!=-1)
            return dp[n];
        int append = solve(n-1,nums,dp)+nums[n-1];
        int New = nums[n-1];
        return dp[n]= max(append,New);
        
    }
    int maxSubArray(vector<int>& nums) {
        int maxSum = -1e7;
        int n = nums.size();
        int sum = nums[0];
        vector<int>dp(n+1,-1);
        int ans = solve(n,nums,dp);
        // for(int i:dp)
        //     cout<<i<<" ";
        dp[0] = -1e7;
        return *max_element(dp.begin(),dp.end());
    }
};