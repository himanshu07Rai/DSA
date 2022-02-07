class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0,r=n-1,t=-1;
        vector<int>ans;
        while(l<=r)
        {
            int m = l+(r-l)/2;
            int val = nums[m];
            if(val==target)
            {
                t=m;
                r=m-1;
            }
                
            else if(val>target)
                r=m-1;
            else l=m+1;
        }
        ans.push_back(t);
        
        l=0,r=n-1;
        while(l<=r)
        {
            int m = l+(r-l)/2;
            int val = nums[m];
            if(val==target)
            {
                t=m;
                l=m+1;
            }
            else if(val>target)
                r=m-1;
            else l=m+1;
        }
        ans.push_back(t);
        return ans;
        
    }
};