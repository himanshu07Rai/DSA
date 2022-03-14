class Solution {
public:
    string simplifyPath(string path) {
       int n = path.length();
        stack<string> st;
        string ans;
        for(int i=0;i<n;i++)
        {
            if(path[i]=='/')
                continue;
            string name="";
            while(i<n && path[i]!='/')
                name+=path[i++];
            if(name=="..")
            {
                if(!st.empty())
                    st.pop();
            }
            else if(name==".")
                continue;
            else
                st.push(name);
            
        }
        
        while(!st.empty())
        {
            ans="/"+st.top()+ans;
            st.pop();
        }
        
        if(ans.length()==0)
            return "/";
        return ans;
    }
};