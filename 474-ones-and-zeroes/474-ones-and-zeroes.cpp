class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(strs.size(),-1)));
        
        return findMax(strs,m,n,0,dp);
    }
    int findMax(vector<string>& strs, int m, int n,int index,vector<vector<vector<int>>> &dp)
    {
        
        if(index==strs.size())
            return 0;
        
        if(dp[m][n][index]!=-1)
            return dp[m][n][index];
        
        int zeroCount = count(strs[index].begin(),strs[index].end(),'0');
        int oneCount = strs[index].size()-zeroCount;
        
        if(m-zeroCount >=0 && n-oneCount>=0)
            return dp[m][n][index] = max(1+findMax(strs,m-zeroCount,n-oneCount,index+1,dp),
                       findMax(strs,m,n,index+1,dp));
        
        return dp[m][n][index] = findMax(strs,m,n,index+1,dp);
    }
};