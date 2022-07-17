class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>> &dp)
    {
        if(i==triangle.size()-1)
            return triangle[triangle.size()-1][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int d = solve(i+1,j,triangle,dp);
        int r = solve(i+1,j+1,triangle,dp);
        return dp[i][j] = triangle[i][j]+min(d,r);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        // for ( int i = triangle.size() - 2; i>= 0 ; --i )
        //     for ( int j = 0; j < triangle[i].size() ; ++ j )
        //         mini[j] = triangle[i][j] + min(mini[j],mini[j+1]);
        // return mini[0];
        return solve(0,0,triangle,dp);
    }
};