class Solution {
public:
    void solve(vector<int>& nums,vector<int>& curr,vector<vector<int>>& ans,int freq[])
    {
        if(curr.size()==nums.size())
        {
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!freq[i])
            {
                curr.push_back(nums[i]);
                freq[i]=1;
                solve(nums,curr,ans,freq);
                freq[i]=0;
                curr.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++) freq[i]=0;
        solve(nums,curr,ans,freq);
        return ans;
    }
};