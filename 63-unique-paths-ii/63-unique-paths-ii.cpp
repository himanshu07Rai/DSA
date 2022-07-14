class Solution {
public:
    int solve(int i,int j,vector<vector<int> > &obstacleGrid,vector<vector<int> > &dp)
    {
        if(i==0 && j==0)
            return !obstacleGrid[i][j];
        if(i<0 || j<0 || obstacleGrid[i][j])
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up = solve(i-1,j,obstacleGrid,dp);
        int left = solve(i,j-1,obstacleGrid,dp);
        return up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        cout<<!obstacleGrid[0][0]<<"\n";
        dp[0][0] = !obstacleGrid[0][0];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                     dp[0][0] = !obstacleGrid[0][0];
                else if(!obstacleGrid[i][j])
                {
                    int up = 0,left = 0;
                    if(i>0)up=dp[i-1][j];
                    if(j>0)left = dp[i][j-1];
                    dp[i][j] = up+left;
                }
            }
        }
        // return solve(m-1,n-1,obstacleGrid,dp);
        return dp[m-1][n-1];
        
    }
};