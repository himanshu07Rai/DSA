class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(),l2=s2.length(),l3=s3.length();
        if(l1+l2!=l3)
            return false;
        vector<vector<int>> dp(l1+1,vector<int>(l2+1));
       
        for(int i=0;i<=l1;i++)
        {
            for(int j=0;j<=l2;j++)
            {
                if(i==0 && j==0)
                    dp[i][j] = true;
                else if(i==0)
                {
                    dp[i][j] = dp[i][j-1] && (s2[j-1]==s3[i+j-1]);
                }
                else if(j==0)
                {
                    dp[i][j] = dp[i-1][j]&& (s1[i-1]==s3[i+j-1]);
                }
                else{
                    dp[i][j] = (dp[i-1][j] && (s1[i-1]==s3[i+j-1])) || (dp[i][j-1] && (s2[j-1]==s3[i+j-1]));
                }
            }
        }
        
        return dp[l1][l2];
        
    }
};