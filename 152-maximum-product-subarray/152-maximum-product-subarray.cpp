class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size(),
        ans = nums[0],
        max_prod = nums[0],
        min_prod = nums[0];
        for(int i=1;i<n;i++){
            
            if(nums[i]<0)
                swap(min_prod,max_prod);
        
            max_prod = max(max_prod*nums[i],nums[i]);
            min_prod = min(min_prod*nums[i],nums[i]);
            ans = max(max_prod,ans);
        }
        return ans;
    }
};