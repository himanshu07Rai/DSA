class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(),Max = 1,lastIdx=0;
        vector<int>dp(n,1),parent(n,0);
        int ans = 1;
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            for(int prev = 0;prev<i;prev++)
            {
                if(nums[i]>nums[prev])
                {
                    if(dp[prev]+1>dp[i])
                    {
                        dp[i] = 1+dp[prev];
                        parent[i]=prev;
                    }
                }
            }
            if(dp[i]>ans)
            {
                ans = dp[i];
                lastIdx=i;
            }
        }
        vector<int>temp;
        temp.push_back(nums[lastIdx]);
        while(parent[lastIdx]!=lastIdx)
        {
            lastIdx = parent[lastIdx];
            temp.push_back(nums[lastIdx]);
        }
        
        reverse(temp.begin(),temp.end());
        for(int i:temp)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
        return ans;
    }
};