class Solution {
public:
    string simplifyPath(string path) {
        
        int n = path.length();
        string ans;
        stack<string> st;
        for(int i=0;i<n;i++)
        {
            if(path[i]=='/')
                continue;
            string directory_name;
            while(i<n && path[i]!='/')
            {
                directory_name+=path[i++];
            }
            if(directory_name==".")
                continue;
            else if(directory_name=="..")
            {
                if(!st.empty())
                    st.pop();
            }
            else{
                st.push(directory_name);
            }
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