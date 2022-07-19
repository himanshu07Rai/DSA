class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = -1e7;
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum = sum+nums[i];
            maxSum = max(maxSum,sum);
            sum = max(0,sum);
        }
        return maxSum;
    }
};