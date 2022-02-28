class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        queue<int> q;
        bool f = false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push(i*100+j);
                }                    
            }
        }
        vector<vector<int>> dir = {
            {0,-1},
            {-1,0},
            {0,1},
            {1,0}
        };
        int min = 0;
        while(!q.empty())
        {
            int size = q.size();
            f = false;
            while(size--)
            {
                int front = q.front();
                q.pop();
                int i = front/100;
                int j = front%100;
                for(auto d:dir)
                {
                    int new_i = i+d[0],new_j = j+d[1];
                    if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && grid[new_i][new_j]==1)
                    {      
                        if(!f)
                            f = true;
                        grid[new_i][new_j]=2;    
                        q.push(new_i*100+new_j);
                    }
                }
            }
            if(f)
                min++;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }     
                
            }            
        }
        return min;
    }
};