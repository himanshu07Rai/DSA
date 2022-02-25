class Solution {
public:
    bool isValid(int i,int j,int n,int m)
    {
        return i<n && i>=0 && j<m && j>=0;
    }
    void countComponents(int i,int j,vector<vector<char>>& grid)
    {
        int n = grid.size(),m = grid[0].size();
        grid[i][j] = '0';
        int forI[]={0,-1,0,1},forJ[] = {-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int new_i = i+forI[k],new_j = j+forJ[k];
            if(isValid(new_i,new_j,n,m) && grid[new_i][new_j]=='1' )
                countComponents(new_i,new_j,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                   countComponents(i,j,grid); 
                    ans++;
                }                   
                
            }
        }
        return ans;
        
    }
};