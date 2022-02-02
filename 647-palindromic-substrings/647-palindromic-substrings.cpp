class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        vector<vector<bool>> dp(n,vector<bool>(n));
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g;j<n;i++,j++)
            {
                if(!g)
                {
                    dp[i][j] = true;
                    ans++;
                }else if(g==1){
                    if(s[i]==s[j])
                    {
                         dp[i][j] = true;
                        ans++;
                    }
                }else{
                    bool c = s[i]==s[j] && dp[i+1][j-1];
                    if(c){
                         dp[i][j] = true;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};