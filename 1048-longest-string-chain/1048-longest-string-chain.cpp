class Solution {
public:
    static bool comp(string &s1,string &s2)
    {
        return s1.length()<s2.length();
    }
    bool isPossible(string &s1,string &s2)
    {
        if(s1.length()!=s2.length()+1)
            return false;
        int i=0,j=0;
        while(i<s1.length())
        {
            if(s1[i]==s2[j])
            {
                i++,j++;
            }else{
                i++;
            }
        }
        return i==s1.length() && j==s2.length();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size(),ans=1;
        sort(words.begin(),words.end(),comp);
        vector<int>dp(n,1);
        for(int i=1;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(isPossible(words[i],words[prev])&&dp[prev]+1>dp[i])
                    dp[i]=dp[prev]+1;
            }
            ans = max(ans,dp[i]);
        }
        return ans;
        
    }
};