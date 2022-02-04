class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans;
        int n = nums.size();
        int l=0,r=n;
        while(l<r)
        {
            int m = l+(r-l)/2;
            int val = nums[m];
            // cout<<val<<"\n";
            if(val==target)
                return m;
            else if(val>=target)
            {
                r=m;
            }
            else l=m+1;
        }
        return l;
    }
};