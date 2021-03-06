class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       
        int n = nums.size();
        int l=0,r=n;
        int ans = n;
        while(l<r)
        {
            int m = l+(r-l)/2;
            if(nums[m]==target)
                return m;
            if(nums[m]>=target)
            {
                r = m;
            }   
            else l=m+1;
        }
        return l;
        
    }
};