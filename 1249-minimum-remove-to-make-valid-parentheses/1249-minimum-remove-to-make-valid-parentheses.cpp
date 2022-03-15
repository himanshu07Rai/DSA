class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        unordered_map<int,bool>m;
        string ans="";
        stack<char>st;
        int f = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                // cout<<s[i]<<" ";
                // st.push(s[i]);
                f++;
            }
            else if(s[i]==')') 
            {
                if(f)
                {
                    // cout<<f<<s[i]<<" ";
                    // st.push(s[i]);
                    f--;
                }else{
                    m[i] = true;
                }
                
            }
            else {
                // cout<<s[i]<<" ";
                st.push(s[i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                // cout<<s[i]<<" ";
                // st.push(s[i]);
                f++;
            }
            else if(s[i]==')') 
            {
                if(f)
                {
                    // cout<<f<<s[i]<<" ";
                    // st.push(s[i]);
                    f--;
                }else{
                    m[i] = true;
                }
                
            }
            else {
                // cout<<s[i]<<" ";
                // st.push(s[i]);
                continue;
            }
        }
        f=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==')')
            {
                // cout<<s[i]<<" ";
                // st.push(s[i]);
                f++;
            }
            else if(s[i]=='(') 
            {
                if(f)
                {
                    // cout<<f<<s[i]<<" ";
                    // st.push(s[i]);
                    f--;
                }else{
                    m[i] = true;
                }
                
            }
            else {
                // cout<<s[i]<<" ";
                // st.push(s[i]);
                continue;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(m.find(i)==m.end())
                ans+=s[i];
        }
//         string t = "";
//         f = 0;
//         while(!st.empty())
//         {
//             t=st.top()+t;
//             if(st.top()==')'){
//                 f++;
//                 ans = st.top()+ans;
//             }else if(st.top()=='(')
//             {
//                 if(f)
//                 {
//                     f--;
//                     ans = st.top()+ans;
//                 }
                
//             }else ans = st.top()+ans;
            
//             st.pop();
                
//         }
        // cout<<"\n"<<t;
        
        return ans;
        
    }
};