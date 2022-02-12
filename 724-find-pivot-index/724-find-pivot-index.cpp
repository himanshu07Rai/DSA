class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int lSum = 0;
        int rSum=totalSum-lSum;
        for(int i=0;i<n;i++)
        {
            rSum-=nums[i];
            if(rSum==lSum)
                return i;
            lSum+=nums[i];
        }
        return -1;
    }
};