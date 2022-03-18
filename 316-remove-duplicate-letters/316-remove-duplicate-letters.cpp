class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> m;
        vector<bool> isPresent(26,false);
        vector<int> lastIndex(26,0);
        string ans="";
        for(int i=0;i<s.length();i++)
                lastIndex[s[i]-'a'] = i; 
        stack<char> st;
        
        for(int i=0;i<s.length();i++)
        {
            int c = s[i]-'a';
            if(isPresent[c]) continue;
            while(!st.empty() && st.top()>c && i<lastIndex[st.top()])
            {
                isPresent[st.top()] = false;
                st.pop();                
            }
            st.push(c);
            isPresent[c] = true;
        }
        
        while(!st.empty())
        {
            ans+=st.top()+'a';
            st.pop();
        }
            
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};