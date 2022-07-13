class Solution {
public:
    int solve(vector<int>& nums,int l) {
        int n = nums.size();
        int x = 0;
        int y = nums[l];
        for(int i=2;i<n;i++)
        {
            int pick = nums[l+i-1]+x;
            int notPick = y;
            int z = max(pick,notPick);
            x = y;
            y = z;
        }
        return y;
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