class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& heights,int prev,vector<vector<bool>> &ocean,vector<vector<int>> &dir)
    {
        if(i<0 || i>=heights.size() || j<0 || j>=heights[0].size() || heights[i][j]<prev||ocean[i][j])
            return;
        ocean[i][j] = true;
        for(auto d:dir)
        {
            dfs(i+d[0],j+d[1],heights,heights[i][j],ocean,dir);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int n = heights.size(), m = heights[0].size();
        if(!n)
            return ans;
        vector<vector<bool>>pacific(n,vector<bool>(m,false));
        vector<vector<bool>>atlantic(n,vector<bool>(m,false));
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        
         for(int j=0;j<m;j++)
        {
            dfs(0,j,heights,INT_MIN,pacific,dir);
            dfs(n-1,j,heights,INT_MIN,atlantic,dir);
        }

        for(int i=0;i<n;i++)
        {
            dfs(i,0,heights,INT_MIN,pacific,dir);
            dfs(i,m-1,heights,INT_MIN,atlantic,dir);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};