class Solution {
public:
    int solve(vector<int>& nums,int l) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = 0;
        dp[1] = nums[l];
        for(int i=2;i<n;i++)
        {
            int pick = nums[l+i-1]+dp[i-2];
            int notPick = dp[i-1];
            dp[i] = max(pick,notPick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        // cout<<solve(nums,0,n-2)<<" "<<solve(nums,1,n-1);
        return max(solve(nums,0),solve(nums,1));
    }
};