class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 1,t=nums[0],n=nums.size();
        int j=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==t)
            {
                continue;
            }
                
            else{
                t = nums[i];
                swap(nums[i],nums[j]);
                j++;
                ans++;
            }
        }
        return ans;
    }
};