class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = -1e7;
        int curr = 1;
        for(int i=0;i<n;i++)
        {
            curr*=nums[i];
            ans = max(ans,curr);
            if(curr==0)
                curr = 1;
        }
        curr = 1;
        for(int i=n-1;i>=0;i--)
        {
            curr*=nums[i];
            ans = max(ans,curr);
            if(curr==0)
                curr = 1;
        }
        return ans;
    }
};