class Solution {
public:
    bool isPalindromic(string &s,int i,int j)
    {
        if(i>=j)
            return true;
        if(s[i]!=s[j])
            return false;
        return isPalindromic(s,i+1,j-1);
        
    }
    int solve(int i,int n,string &s, vector<int>&dp)
    {
        if(i==n)
            return 0;
        int res = INT_MAX;
        if(dp[i]!=-1)
            return dp[i];
        for(int j=i;j<n;j++)
        {
            if(isPalindromic(s,i,j))
            {
                int cost = 1+solve(j+1,n,s,dp);
                res = min(cost,res);
            }
        }
        return dp[i]=res;
    }
    int minCut(string s) {
        vector<int>dp(s.length()+1,0);
        int n = s.length();
        for(int i=n-1;i>=0;i--)
        {
            int res = INT_MAX;
            for(int j=i;j<n;j++)
            {
                if(isPalindromic(s,i,j))
                {
                    int cost = 1+dp[j+1];
                    res = min(cost,res);
                }
            }
            dp[i]=res;
        }
        return dp[0]-1;
    }
};