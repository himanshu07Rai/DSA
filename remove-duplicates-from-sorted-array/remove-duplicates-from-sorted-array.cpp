class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int t=nums[0],n=nums.size();
        int j=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=t)
            {
                t = nums[i];
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return j;
    }
};