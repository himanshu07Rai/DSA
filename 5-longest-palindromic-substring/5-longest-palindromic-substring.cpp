class Solution {
public:
    string help(string s,int i,int j)
    {
        int n = s.length();
        while(i>=0 && j<n && s[i]==s[j])
        {
            i--,j++;
        }
        i++,j--;
        return s.substr(i,j-i+1);
    }
    string longestPalindrome(string s) {
        int n = s.length();
        if(!n)
            return "";
        if(n==1)
            return s;
        string ans;
        for(int i=0;i<n-1;i++)
        {
            string temp;
            temp = help(s,i,i);
            if(temp.size()>ans.length())
                ans = temp;
            if(s[i]==s[i+1])
            {
                temp = help(s,i,i+1);
                if(temp.size()>ans.length())
                    ans = temp;
            }
                
        }
        return ans;
    }
};