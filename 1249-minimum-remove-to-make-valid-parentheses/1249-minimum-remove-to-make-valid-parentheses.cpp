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
                st.push(i);
            }
            else if(s[i]==')') 
            {
                if(st.empty())
                    s[i] = '#';
                else st.pop();
                
            }
        }
        
        while(!st.empty())
        {
            s[st.top()]='#';
            st.pop();
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]!='#')
                ans+=s[i];
        }
        
        return ans;
        
    }
};