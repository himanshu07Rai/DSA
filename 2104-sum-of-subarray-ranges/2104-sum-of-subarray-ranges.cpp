class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        
        long long ans=0;
        
        for(int i=0;i<n-1;i++)
        {
            int mi = nums[i],mx = nums[i];
            for(int j=i+1;j<n;j++)
            {
                mx = max(mx,nums[j]);
                mi = min(mi,nums[j]);
                ans+=mx-mi;
            }
            
        }
        
        return ans;
    }
};