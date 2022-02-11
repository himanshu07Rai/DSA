class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> m;
        m[0] = -1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i]==0?-1:1;
            auto it = m.find(sum);
            if(it!=m.end())
            {
                ans = max(ans,i-m[sum]);
            }
            else m[sum] = i;
        }
        return ans;
    }
};