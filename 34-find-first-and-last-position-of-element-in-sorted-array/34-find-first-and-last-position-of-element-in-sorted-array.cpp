class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0,r=n-1;
        vector<int>ans(2,-1);
        while(l<=r)
        {
            int m = l+(r-l)/2;
            int val = nums[m];
            if(val==target)
            {
                ans[0]=m;
                r=m-1;
            }
                
            else if(val>target)
                r=m-1;
            else l=m+1;
        }
        
        l=0,r=n-1;
        while(l<=r)
        {
            int m = l+(r-l)/2;
            int val = nums[m];
            if(val==target)
            {
                ans[1]=m;
                l=m+1;
            }
            else if(val>target)
                r=m-1;
            else l=m+1;
        }
        return ans;
        
    }
};