class Solution {
public:
    void dfs(int l,int h,int i,int num,vector<int>&ans)
    {
        if(num>=l && num<=h)
            ans.push_back(num);
        if(num>h or i>9)
            return;
        dfs(l,h,i+1,num*10+i,ans);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i=1;i<=9;i++)
            dfs(low,high,i,0,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};