class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>mir(n),mil(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty())
                mir[i]=n;
            else mir[i]=st.top();
            st.push(i);
        }
        int ans = 0;
        while(!st.empty())
            st.pop();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty())
                mil[i]=-1;
            else mil[i]=st.top();
            st.push(i);
            ans = max(ans,(mir[i]-mil[i]-1)*heights[i]);
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<mil[i]<<" "<<mir[i]<<"\n";
        // }
        return ans;
        
    }
};