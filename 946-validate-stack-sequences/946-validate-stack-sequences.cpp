class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0,j=0;
        int n = pushed.size();
        if(pushed[i]!=popped[j])
            while(pushed[i]!=popped[j])
            st.push(pushed[i++]);     
        
        
        while(i<n)
        {
            while(!st.empty() && st.top()==popped[j])
            {
                st.pop();
                j++;
            }
            
            st.push(pushed[i++]);                
            
        }
        
        while(!st.empty() && st.top()==popped[j])
        {
            st.pop();
            j++;
        }
        
        return st.empty();
    }
};