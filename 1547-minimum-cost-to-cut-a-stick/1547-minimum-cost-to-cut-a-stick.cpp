class Solution {
public:
    int solve(int i,int j,vector<int>& cuts,vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int res = INT_MAX;
        for(int k=i;k<=j;k++)
        {
            int cost = cuts[j+1]-cuts[i-1]+solve(i,k-1,cuts,dp)+solve(k+1,j,cuts,dp);
            res = min(res,cost);
        }
        return dp[i][j]= res;
    }
    int minCost(int n, vector<int>& cuts) {
        int j = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        n = cuts.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(1,j,cuts,dp);
         
    }
};