class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(!n)
            return "";
        int start,length;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g;j<n;j++,i++)
            {
                if(!g){
                    dp[i][j] = true;
                    start = i,length = g+1;
                }
                else if(g==1){
                    if(s[i]==s[j]){
                         dp[i][j] = true;
                         start = i,length = g+1;
                    }
                }
                else{
                    dp[i][j] = s[i]==s[j] && dp[i+1][j-1];
                    if(dp[i][j]){
                        start = i,length = g+1;
                    }
                }
            }
        }
        return s.substr(start,length);
    }
};