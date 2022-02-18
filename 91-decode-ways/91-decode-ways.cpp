class Solution {
public:
    int help(int i, string &s,vector<int>&dp) {
        int n = s.size();
        if(i == n) return 1;
        if(dp[i]!=-1)
            return dp[i];
        int op1 = s[i]-'0';
        if(op1 == 0) return 0; // sub string starting with 0 is not a valid encoding
        int res = help(i+1,s,dp);
        int op2 = (s[i]-'0')*10+s[i+1]-'0';
        if( i < n-1 && op2<27) res += help(i+2,s,dp);
        return dp[i] = res;
    }
    int numDecodings(string s) {
        vector<int>dp(101,-1);
        return help(0,s,dp);
    }
};