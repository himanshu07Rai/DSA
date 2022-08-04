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
        vector<int>dp(s.length(),-1);
        return solve(0,s.length(),s,dp)-1;
    }
};