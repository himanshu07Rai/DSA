class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto time : times)
        {
            adj[time[0]].push_back({time[1],time[2]});
        }
        vector<int> d(n+1,INT_MAX);
        d[0]=0,d[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto [d1,u] = pq.top();
            pq.pop();
            for(auto it : adj[u])
            {
                auto [v,d2] = it;
                if(d[v]>d1+d2)
                {
                    d[v] = d1+d2;
                    pq.push({d[v],v});
                }
                
            }
        }
        int res = *max_element(d.begin(),d.end());
        return res==INT_MAX?-1:res;
    }
};