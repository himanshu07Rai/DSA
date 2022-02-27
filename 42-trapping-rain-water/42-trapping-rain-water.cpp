class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>ans;
        int n = height.size(),i;
        int max_till_i = 0;
        for(i=0;i<n;i++)
        {
            max_till_i=max(max_till_i,height[i]);
            ans.push_back(max_till_i-height[i]);
        }
        max_till_i = 0;
        for(i=n-1;i>=0;i--)
        {
            max_till_i=max(max_till_i,height[i]);
            ans[i]=min(ans[i],max_till_i-height[i]);
        }
        i=0;
        for(auto j:ans)
            i+=j;
        return i;
    }
};