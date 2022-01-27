class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        vector<int>ans;
        vector<vector<int>> g(n);
        vector<int>degree(n,0);
        for(auto e:edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(degree[i]==1)
                q.push(i);
        }   
        
        while(!q.empty())
        {
            vector<int>temp;
            int s = q.size();
            while(s--)
            {
                int par = q.front();
                temp.push_back(par);
                q.pop();
                for(int child:g[par])
                {
                    degree[child]--;
                    if(degree[child]==1)
                        q.push(child);
                }
            }
            ans = temp;
        }        
        return ans;
    }
};