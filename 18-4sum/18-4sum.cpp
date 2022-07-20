class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //O(N^3)
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        //very imp to remove duplicates
        if(i>0 && nums[i]==nums[i-1])
            continue;
        long long target_3 = (long long)target-nums[i];
        for(int j=i+1;j<n;j++)
        {
            //very imp to remove duplicates
            if(j>i+1 && nums[j]==nums[j-1])
            continue;
            
            //overflowing int,that's why *1L(typecasting to long)
            long long target_2 = (long long)target_3-nums[j];
            
            int s=j+1,e=n-1;
            while(s<e)
            {
                if(nums[s]+nums[e] < target_2)
                    s++;
                else if(nums[s]+nums[e] > target_2)
                    e--;
                else
                {
                    ans.push_back({nums[i],nums[j],nums[s],nums[e]});
                    
                    int val=nums[s];
                    while(s<e && nums[s]==val)
                        s++;
                    
                    val=nums[e];
                    while(s<e && nums[e]==val)
                        e--;
                }
            }
        }
    }
    return ans;
}
};