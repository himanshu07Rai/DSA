class Solution {
public:
    
    bool isValid(char now)
    {
        return now!='0';
    }
    
    bool isValid(char prev, char now)
    {
        if(prev=='1' || (prev=='2' && now<'7')) return true;
        return false;
    }
    
    int numDecodings(string s) {
        int n =s.size();
        if(n==0 || s[0]=='0') return 0;
        if(n==1)return 1;
        vector<int>dp(n,0);
        dp[0] = 1;
        if(isValid(s[1]))
            dp[1]=dp[0];
        if(isValid(s[0],s[1]))
            dp[1]+=dp[0];  
        for(int i=2;i<n;++i)
        {
            if(isValid(s[i]))
            {
                dp[i]=dp[i-1];
                if(isValid(s[i-1], s[i])) dp[i]+=dp[i-2];
            }
            
            else if(isValid(s[i-1],s[i]))
                dp[i]=dp[i-2];
            
            else dp[i]=0;
            
        }
        return dp[n-1];
    }
//     int help(int i, string &s,vector<int>&dp) {
//         int n = s.size();
//         if(i == n) return 1;
//         if(dp[i]!=-1)
//             return dp[i];
//         int op1 = s[i]-'0';
//         if(op1 == 0) return 0; // sub string starting with 0 is not a valid encoding
//         int res = help(i+1,s,dp);
//         int op2 = (s[i]-'0')*10+s[i+1]-'0';
//         if( i < n-1 && op2<27) res += help(i+2,s,dp);
//         return dp[i] = res;
//     }
//     int numDecodings(string s) {
//         int n = s.size();
//         vector<int>dp(101,-1);
//         dp[n] = 1;
        
//         return help(0,s,dp);
//     }
};