class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        stack<pair<char,int>> st;
        for(char c:s)
        {
            if(st.empty() || st.top().first!=c)
            {
                st.push({c,1});
            }
            else{
                st.top().second++;
                if(st.top().second==k)
                    st.pop();
            }
        }
        string ans = "";
        while(!st.empty())
        {
            auto p = st.top();
            st.pop();
            for(int i=0;i<p.second;i++)
                ans+=p.first;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};