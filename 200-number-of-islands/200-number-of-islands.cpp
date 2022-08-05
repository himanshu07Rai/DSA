class Solution {
public:
    bool isNeighbour(int i,int j,int n,int m)
    {
        return i>=0 && i<n && j>=0 && j<m;
    }
    void dfs(vector<vector<char>>& grid,vector<vector<bool>> &visited, int i,int j,int n,int m)
    {
        visited[i][j]=true;
        int for_i[]={0,-1,0,1},for_j[]={-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int ni=i+for_i[k],nj=j+for_j[k];
            if(isNeighbour(ni,nj,n,m) && grid[ni][nj]=='1' && !visited[ni][nj])
                dfs(grid,visited,ni,nj,n,m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(),m = grid[0].size();
        if(!n)
            return 0;
        int count = 0;
        vector<vector<bool>> visited(n,vector<bool>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    count++;
                    dfs(grid, visited, i, j,n,m);
                }
            }
        }
        

    return count;
    }
};