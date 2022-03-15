class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
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
                {
                    f--;
                }else{
                    m[i] = true;
                }
                
            }
            else {
                continue;
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
                {
                    f--;
                }else{
                    m[i] = true;
                }
                
            }
            else {
                continue;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(m.find(i)==m.end())
                ans+=s[i];
        }
        
        return ans;
        
    }
};