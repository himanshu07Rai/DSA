class Solution {
public:
    int ok(char prev, char now)
    {
        if(prev=='1' || (prev=='2' && now<'7')) return 1;
        return 0;
    }
    int ok(char now)
    {
        if(now!='0') return 1;
        return 0;
    }
    int numDecodings(string s) {
        int n =s.size();
        if(n==0 || s[0]=='0') return 0;
        int num=1,prev1=1,prev2=1;  
        for(int i=1;i<n;++i)
        {
            if(ok(s[i]))
            {
                num=prev1;
                if(ok(s[i-1], s[i])) num+=prev2;
            }
            else 
            {
                if(ok(s[i-1],s[i])) num=prev2;
                else num=0;
            }
            prev2=prev1;
            prev1=num;
        }
        return num;
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