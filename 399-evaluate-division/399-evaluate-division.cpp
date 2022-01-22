class Solution {
public:
    
    map<string,vector<pair<string,double>>> buildGraph(vector<vector<string>>& e, vector<double>& v)
    {        
        map<string,vector<pair<string,double>>> m;
        
        for(int i=0;i<e.size();i++){
            string src = e[i][0],dest = e[i][1];
            double val = v[i];
            m[src].push_back({dest,val});
            m[dest].push_back({src,1/val});
        }
        return m;
    }
    
    double dfs(string src,string dest,set<string> &visited,map<string,vector<pair<string,double>>>&g)
    {
        if(g.find(src)==g.end() || g.find(dest)==g.end() )
            return -1.0;
        if(src==dest)
            return 1.0;
        visited.insert(src);
        for(auto ng:g[src]){
            if(visited.find(ng.first)==visited.end())
            {
                double ans = dfs(ng.first,dest,visited,g);
                if(ans!=-1.0)
                    return ans*ng.second;
            }
        }
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        map<string,vector<pair<string,double>>> g;
        g = buildGraph(e,v);        
        vector<double> ans(q.size());
        for(int i=0;i<q.size();i++)
        {
            string s=q[i][0];
            string d=q[i][1];
            set<string>visited;
            ans[i] = dfs(q[i][0],q[i][1],visited,g);
        }
        
        return ans;
        
    }
};