class Solution {
public:
    void generate(int idx,vector<int>& nums,vector<int>& curr,int target,vector<vector<int>> &ans)
    {
        if(target<0)
        {
            return;
        }
        if(idx==nums.size()){
            if(target==0)
            {
                ans.push_back(curr);
                
            }
            return;
        }
            
        
        generate(idx+1,nums,curr,target,ans);
        if(nums[idx]<=target)
        {
            curr.push_back(nums[idx]);
            generate(idx,nums,curr,target-nums[idx],ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>temp;
        generate(0,candidates,temp,target,ans);
        return ans;
    }
};