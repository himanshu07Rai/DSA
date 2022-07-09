class Solution {
public:
    void solve(int start,vector<int>&arr,vector<int>& curr,vector<vector<int>> &ans)
    {
        if(start==arr.size())
        {
            ans.push_back(curr);
            return;
        }
        solve(start+1,arr,curr,ans);
        curr.push_back(arr[start]);
        solve(start+1,arr,curr,ans);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
        vector<int> curr;
        solve(0,nums,curr,ans);
        return ans;
    }
};