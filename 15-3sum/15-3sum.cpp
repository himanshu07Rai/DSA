class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>0  && nums[i]==nums[i-1])
                continue;
                
            int target_2 = -nums[i];
            int l = i+1,r=n-1;
            while(l<r)
            {
                if(nums[l]+nums[r] < target_2)
                    l++;
                else if(nums[l]+nums[r] > target_2)
                    r--;
                else
                {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    
                    int val=nums[l];
                    while(l<r && nums[l]==val)
                        l++;
                    
                    val=nums[r];
                    while(l<r && nums[r]==val)
                        r--;
                }
            }
            
        }
        return ans;
    }
};