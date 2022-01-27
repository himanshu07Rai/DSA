class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxHeight = -1e5;
        int n = height.size();
        int l=0,r=n-1;
        while(l<r)
        {
            int curr = min(height[l],height[r])*(r-l);
            maxHeight = max(maxHeight,curr);
            if(height[l]>height[r])
                r--;
            else l++;
        }
        return maxHeight;
    }
};