class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = -1e7;
        int n = nums.size();
        int sum = nums[0];
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            dp[i] = max(dp[i-1]+nums[i-1],nums[i-1]);
            maxSum=max(dp[i],maxSum);
            
        }
        return maxSum;
    }
};