class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0,h = n-1;
        if(nums[l] <=nums[h])
            return nums[l];
        while(l<=h)
        {
            int m = l+(h-l)/2;
            if(nums[m]>nums[m+1])
                return nums[m+1];
            
            if(nums[m]<nums[m-1])
                return nums[m];
            
            if(nums[m]>=nums[l])
                l=m+1;
            else h = m-1;
        }
        return nums[0];
    }
};