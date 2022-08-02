class Solution {
public:
    int solve(int i,int prev,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i==nums.size())
            return 0;
        if(dp[i][prev+1]!=-1)
            return dp[i][prev+1];
        int notTake = solve(i+1,prev,nums,dp);
        int take = INT_MIN;
        if(prev==-1 || nums[i]>nums[prev])
            take = 1+solve(i+1,i,nums,dp);
        return dp[i][prev+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(),Max = 1,lastIdx=0;
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
        // vector<int>dp(n,1),map(n,0);
            
//         for(int i=0;i<n;i++)
//         {
//             map[i] = i;
//             for(int prev=0;prev<i;prev++)
//             {
//                 if(nums[prev]<nums[i] && 1+dp[prev]>dp[i])
//                 {
//                     dp[i] = 1+dp[prev];
//                     map[i] = prev;
//                 }                    
//             }
//             if(dp[i]>Max)
//             {
//                 Max = dp[i];
//                 lastIdx = i;
//             }
//         }
//         vector<int> temp;
//         temp.push_back(nums[lastIdx]);
//         while(map[lastIdx]!=lastIdx)
//         {
//             lastIdx = map[lastIdx];
//             temp.push_back(nums[lastIdx]);
//         }
//         reverse(temp.begin(),temp.end());
//         for(int i:temp)
//             cout<<i<<" ";
//         return Max;
    }
};