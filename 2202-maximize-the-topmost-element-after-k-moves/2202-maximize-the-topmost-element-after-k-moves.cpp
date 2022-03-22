class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {\
        if(k == 0) return nums[0];
  
        if(k %2 != 0 && nums.size()==1) return -1;
        
        int n = nums.size();
        int i=0, maxm = 0;
        
        while(i < n && i < k-1){
            maxm = max(maxm, nums[i]);
            i++;
        }
        
        int ans = 0;
                                              
        if(k < n) ans = nums[k];
        return max(maxm, ans);
    }
        
        
};