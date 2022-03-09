#include<bits/stdc++.h>

using namespace std;

string printLCS(string X,string Y,int n,int m, vector<vector<int>> &dp)
{
    if(n==0 || m==0)
    return string("");
    if(X[n-1]==Y[m-1])
    {
        return printLCS(X,Y,n-1,m-1,dp)+X[n-1];
    }
    if(dp[n-1][m]>dp[n][m-1])
    {
        return printLCS(X,Y,n-1,m,dp);
    }
    else{
        return printLCS(X,Y,n,m-1,dp);
    }
}

string LCS(string X,string Y)
{
    int n = X.length(),m = Y.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(X[i-1]==Y[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    return printLCS(X,Y,n,m,dp);


}

int main()
{
    string X = "abc", Y = "asesecftft";

    cout << LCS(X, Y);
 
    return 0;
}