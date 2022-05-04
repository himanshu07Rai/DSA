class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        // sort(nums.begin(),nums.end());
        int i = 0,n = nums.size(),ans=0;
        for(;i<n;i++)
        {
            if(m.find(k-nums[i])!=m.end())
            {
                ans++;
                if(m[k-nums[i]]==1)
                    m.erase(k-nums[i]);
                else m[k-nums[i]]--;
            }
            else m[nums[i]]++;
        }
        return ans;
    }
};