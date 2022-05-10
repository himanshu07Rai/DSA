class Solution {
public:
    void generate(int start,vector<int> &temp,int k,int sum,vector<vector<int>>&ans)
    {
        if(temp.size()==k && sum==0)
        {
            ans.push_back(temp);
            return ;
        }
        for(int i=start;i<=9;i++)
        {
            temp.push_back(i);
            generate(i+1,temp,k,sum-i,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        generate(1,temp,k,n,ans);
        return ans;
    }
};
