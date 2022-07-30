class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(),Max = 1,lastIdx=0;
        vector<int>dp(n,1),map(n,0);
            
        for(int i=0;i<n;i++)
        {
            map[i] = i;
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev]<nums[i] && 1+dp[prev]>dp[i])
                {
                    dp[i] = 1+dp[prev];
                    map[i] = prev;
                }                    
            }
            if(dp[i]>Max)
            {
                Max = dp[i];
                lastIdx = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastIdx]);
        while(map[lastIdx]!=lastIdx)
        {
            lastIdx = map[lastIdx];
            temp.push_back(nums[lastIdx]);
        }
        reverse(temp.begin(),temp.end());
        for(int i:temp)
            cout<<i<<" ";
        return Max;
    }
};