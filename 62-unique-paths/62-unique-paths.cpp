class Solution {
public:
    int countPaths(int i,int j,vector<vector<int>> &dp)
    {
        if(i==0 && j==0)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(i<0 || j<0)
            return 0; 
        int up = countPaths(i-1,j,dp);
        int left = countPaths(i,j-1,dp);
        return dp[i][j]=up+left;
        
    }
    int uniquePaths(int m, int n) {
        if(m==1 && n==1)
            return 1;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    dp[i][j] = 1;
                else{
                    int up = 0,left = 0;
                    if(i>0)up = dp[i-1][j];
                    if(j>0)left = dp[i][j-1];
                    dp[i][j] = up+left;
                }
            }
        }
        // return countPaths(m-1,n-1,dp);

        return dp[m-1][n-1];
    }
};