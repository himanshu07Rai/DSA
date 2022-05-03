class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int Min =  INT_MAX,Max = INT_MIN;
        int n = nums.size();
        if(n==1)
            return 0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                if(nums[i]>nums[i+1])
                {
                    Max = max(Max,nums[i]);
                    Min = min(Min,nums[i]);
                }
            }
            else if(i==n-1){
                if(nums[i]<nums[i-1])
                {
                    Max = max(Max,nums[i]);
                    Min = min(Min,nums[i]);
                }
            }
            else{
                if(nums[i]<nums[i-1] || nums[i]>nums[i+1])
                {
                    Max = max(Max,nums[i]);
                    Min = min(Min,nums[i]);
                }
            }
        }
        
        // cout<<Min<<" "<<Max;
        if(Min ==  INT_MAX || Max == INT_MIN)
            return 0;
        int i,j;
        for(i=0;i<n && nums[i]<=Min;i++);
        for(j=n-1;j>=0 && nums[j]>=Max;j--);
        return j-i+1;
    }
};