class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0,r = n-1;
        while(l<=r)
        {
            int m = l+(r-l)/2;
            int val = nums[m];
            if(val==target)
                return true;
            if(val == nums[l] && val==nums[r])
            {
                l++;
                r--;
            }
            else if(val>=nums[l])
            {
                if(target>=nums[l] && target<=val)
                    r = m-1;
                else
                    l = m+1;
            }
            else {
                if(target>=val && target<=nums[r])
                    l=m+1;
                else r = m-1;
            }
                
        }
        return false;
    }
};