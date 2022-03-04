class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=(nums[i]&1)?1:0;
        }
        unordered_map<int,int> m;
        int sum = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==k)
                ans++;
            if(m.count(sum-k)>0)
            {
                ans+=m[sum-k];
            }
            m[sum]++;
        }
        return ans;
    }
};