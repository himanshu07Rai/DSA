class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = -1e7;
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum>maxSum)
                maxSum = sum;
            if(sum<0)
                sum = 0;
            
        }
        return maxSum;
    }
};