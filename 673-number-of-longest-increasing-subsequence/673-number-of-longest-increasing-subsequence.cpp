class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(),maxi=1;
        vector<int> dp(n,1),cnt(n,1);
        for(int i=1;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]>nums[prev])
                {
                    if(1+dp[prev]>dp[i])
                    {
                        dp[i] = 1+dp[prev];
                        cnt[i]=cnt[prev];
                    }else if(dp[i]==1+dp[prev])
                        cnt[i]+=cnt[prev];
                        
                }
            }
            maxi = max(maxi,dp[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi)
                ans+=cnt[i];
        }
        return ans;
    }
};