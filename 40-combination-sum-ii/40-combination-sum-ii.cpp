class Solution {
public:
    
    void generate(vector<int> &candidates,int start,vector<int> &curr,int target,vector<vector<int>>&ans)
    {
        if(target==0)
        {
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<candidates.size();i++)
        {
            if(i>start && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target)break;
            curr.push_back(candidates[i]);
            generate(candidates,i+1,curr,target-candidates[i],ans);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)    {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        generate(candidates,0,curr,target,ans);
        return ans;
    }
};