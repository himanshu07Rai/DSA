class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        string ans="";
        int f = 0,b=0;
        
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
            
            int j = n-1-i;
            
            if(s[j]==')')
            {
                b++;
            }
            else if(s[j]=='(') 
            {
                if(b)
                    b--;
                else s[j]='#';
                
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