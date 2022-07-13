class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size(); 
        int x = 0;
        int y = nums[0],z;
        for(int i=2;i<=n;i++)
        {
            int pick = nums[i-1];
            if(i>1)
            {
                pick+=x;
            }
            int notPick = y;
            z = max(pick,notPick);
            x=y;
            y=z;
        }
        return y;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        vector<int> woLast,woFirst;
        
        for(int i=0;i<n;i++)
        {
            if(i)
                woFirst.push_back(nums[i]);
            if(i!=n-1)
                woLast.push_back(nums[i]);
        }
        return max(solve(woFirst),solve(woLast));
    }
};