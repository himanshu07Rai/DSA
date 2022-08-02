class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1),parent(n,0);
        int lastIdx = 0,max=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            parent[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i])
                {
                    dp[i] = 1+dp[prev];
                    parent[i] = prev;
                }
                
            }
            if(dp[i]>max)
            {
                max = dp[i];
                lastIdx=i;
            }
        }
        vector<int>t;
        t.push_back(nums[lastIdx]);
        while(parent[lastIdx]!=lastIdx)
        {
            lastIdx=parent[lastIdx];
            t.push_back(nums[lastIdx]);
        }
        return t;
    }
};