class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0,j=0;
        int n1 = pushed.size(),n2=popped.size();
        if(pushed[i]!=popped[j])
            while(pushed[i]!=popped[j])
            st.push(pushed[i++]);     
        
        
        while(i<n1)
        {
            // cout<<i<<" ";
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
        
        // cout<<"\n";
        
        // while(!st.empty())
        // {
        //     cout<<st.top()<<" ";
        //     st.pop();
        // }
        return st.empty();
    }
};