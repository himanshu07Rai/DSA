class Solution {
public:
    bool isValid(int i,int j,int n,int m)
    {
        return i<n && i>=0 && j<m && j>=0;
    }
    void countComponents(int i,int j,vector<vector<char>>& grid,vector<vector<bool>> &visited)
    {
        int n = grid.size(),m = grid[0].size();
        visited[i][j] = true;
        int forI[]={0,-1,0,1},forJ[] = {-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int new_i = i+forI[k],new_j = j+forJ[k];
            if(isValid(new_i,new_j,n,m) && !visited[new_i][new_j]&&grid[i][j]=='1' )
                countComponents(new_i,new_j,grid,visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                   countComponents(i,j,grid,visited); 
                    ans++;
                }                   
                
            }
        }
        return ans;
        
    }
};