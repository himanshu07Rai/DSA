class Solution {
public:     
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(auto &it: nums)    total+=it;
        if(total-target<0 || (total-target)%2) return 0;
        int n = nums.size();
        
        int tar = (total-target)/2;
        vector<int> cur(tar+1, 0), prev(tar+1, 0);

        if(nums[0] == 0)    prev[0] = 2;
        else prev[0] = 1; 

        if(nums[0] != 0 and nums[0] <= tar)
        {
            prev[nums[0]] = 1;         
        }

        for(int index=1; index<n; index++)
        {
            for(int sum=0; sum <= tar; sum++)
            {
                int notTake = prev[sum];
                int take = 0;

                if(nums[index] <= sum)
                   take = prev[sum-nums[index]];


                cur[sum] = (take +notTake); 
            }
            prev = cur;
        }

        return prev[tar]; 
        
    }
        
};