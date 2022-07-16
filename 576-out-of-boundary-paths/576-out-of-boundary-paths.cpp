class Solution {
public:
    int MOD = 1e9+7;
    
    int f(int i, int j, int m, int n, int mx, vector<vector<vector<long long>>>&dp, int MOD) {
        if(i==-1 || j==-1 || i==m || j==n) {
            return 1;
        }
        if(dp[i][j][mx]!=-1)
            return dp[i][j][mx]%MOD;
        long long c1=0, c2=0, c3=0, c4=0;
        if(mx>0) {
            c1=f(i-1, j, m, n, mx-1, dp,MOD)%MOD;
            c2=f(i+1, j, m, n, mx-1, dp,MOD)%MOD;
            c3=f(i, j+1, m, n, mx-1, dp,MOD)%MOD;
            c4=f(i, j-1, m, n, mx-1, dp,MOD)%MOD;
        }
        return dp[i][j][mx]=(c1+c2+c3+c4)%MOD;
    }
    
    int findPaths(int m, int n, int maxMove, int i, int j) {
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(maxMove+1, -1)));
        int MOD = 1e9+7;
        f(i, j, m, n, maxMove, dp,MOD);
        return dp[i][j][maxMove];
    }
};