class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j) {
        if(i<0 || j<0 || i>grid.size()-1 || j>grid[0].size()-1 || grid[i][j]==0)
            return 0;
        
        grid[i][j]=0;
        
        int up=helper(grid, i-1, j);
        int down=helper(grid, i+1, j);
        int right=helper(grid, i, j+1);
        int left=helper(grid, i, j-1);
        
        return up+down+right+left+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0; i<grid.size(); i++) 
            for(int j=0; j<grid[0].size(); j++) 
                if(grid[i][j]==1)
                    ans=max(ans, helper(grid, i, j));
            
        return ans;
    }
};