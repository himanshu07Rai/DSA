class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=4)
            return 0;
        sort(nums.begin(),nums.end());
        
        int minv = INT_MAX;
        minv = min(minv,nums[n-4]-nums[0]);
        minv = min(minv,nums[n-1]-nums[3]);
        minv = min(minv,nums[n-2]-nums[2]);
        minv = min(minv,nums[n-3]-nums[1]);
        return minv;
    }
};