class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int> st;
        unordered_map<int,bool>m;
        string ans="";
        int f = 0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                f++;
            }
            else if(s[i]==')') 
            {
                if(f)
                    f--;
                else s[i]='#';
                
            }
        }
        
        f=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==')')
            {
                f++;
            }
            else if(s[i]=='(') 
            {
                if(f)
                    f--;
                else s[i]='#';
                
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(s[i]!='#')
                ans+=s[i];
        }
        
        return ans;
        
    }
};